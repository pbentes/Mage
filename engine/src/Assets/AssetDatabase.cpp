#include "AssetDatabase.h"

#include <Assets/Asset.h>
#include <Debug/Logger.h>

#include <efsw/efsw.hpp>
#include <sqlite3.h>

#include <cstddef>
#include <cstring>
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>

namespace Engine {
    int callback(void* NotUsed, int argc, char** argv, char** azColName) {
        return 0;
    }

    AssetDatabase::AssetDatabase(std::vector<std::string> directories) : m_AssetDb(nullptr), m_WatchedDirectories(directories) {
        if (sqlite3_open("asset.db", &m_AssetDb)) {
            ERROR("Can't open database: ", sqlite3_errmsg(m_AssetDb));
        } 

        ExecuteQuery(R"(
            CREATE TABLE IF NOT EXISTS assets(
                id        INTEGER PRIMARY KEY AUTOINCREMENT,
                filename  TEXT                NOT NULL,
                extension TEXT                NOT NULL,
                directory TEXT                NOT NULL,
                deleted   BOOL                NOT NULL DEFAULT FALSE,
                scanned   BOOL                NOT NULL DEFAULT TRUE,
                UNIQUE(filename, directory)
            );
        )");
        
        long i = 0;
        for (std::string& directory: m_WatchedDirectories) {
            m_WatchIds[m_FileWatcher.addWatch(directory, this, true)] = i;
            ScanFolder(directory);
        }

        m_FileWatcher.watch();
    }

    AssetDatabase::~AssetDatabase() {
        for (std::pair<const long, int> watchId: m_WatchIds) {
            m_FileWatcher.removeWatch(watchId.first);
        }
        Cleanup();
        sqlite3_close(m_AssetDb);
    }

    std::vector<size_t> AssetDatabase::GetAssetsQuery(std::string query, std::vector<std::string> args) {
        sqlite3_stmt* stmt = CreateStatement(query.c_str());

        int i = 1;
        for (std::string& arg: args) {
            sqlite3_bind_text(stmt, i, arg.c_str(), -1, SQLITE_STATIC);
            i++;
        }

        std::vector<size_t> idVector;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            idVector.push_back((size_t)id);

            if (m_AssetCache.find(id) != m_AssetCache.end())
                continue;
            
            std::string path((char*)sqlite3_column_text(stmt, 1));
            std::string directory((char*)sqlite3_column_text(stmt, 2));
            std::string extension((char*)sqlite3_column_text(stmt, 3));

            std::string fullPath = (std::filesystem::path(m_WatchedDirectories[0]) / (strcmp(directory.c_str(), ".") == 0 ? "" : directory ) / path).string();

            std::shared_ptr<Asset> asset = std::make_shared<Asset>(
                static_cast<size_t>(id),
                fullPath,
                directory,
                extension,
                static_cast<bool>(sqlite3_column_int(stmt, 4))
            );

            this->m_AssetCache[static_cast<size_t>(id)] = asset;
        }

        sqlite3_finalize(stmt);
        return idVector;
    }

    void AssetDatabase::InsertAsset(std::filesystem::path full_path) {
        if (std::filesystem::is_directory(full_path)) {
            return;
        }

        std::string file_name = full_path.filename().string();
        std::string extension = full_path.extension().string();
        std::string directory = normalizePath(full_path.remove_filename().string());
    
        sqlite3_stmt* statement = CreateStatement(R"(
            INSERT INTO assets (filename, extension, directory, deleted) VALUES (?, ?, ?, 0)
                ON CONFLICT(filename, directory) DO UPDATE SET deleted = FALSE, scanned = TRUE;
        )");
        if (statement != nullptr) {
            sqlite3_bind_text(statement, 1, file_name.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 2, extension.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 3, directory.c_str(), -1, SQLITE_STATIC);

            ExecuteStatement(statement);
        }
    }

    void AssetDatabase::UpdateAsset(std::filesystem::path full_path, std::filesystem::path old_full_path) {
        if (std::filesystem::is_directory(full_path)) {
            return;
        }

        std::string extension = full_path.extension().string();
        std::string filename = full_path.filename().string();
        std::string old_filename = old_full_path.filename().string();

        std::string directory = normalizePath(full_path.remove_filename().string());
        std::string old_directory = normalizePath(old_full_path.remove_filename().string());
        
        sqlite3_stmt* statement = CreateStatement(R"(
            UPDATE assets
                SET filename = ?,
                extension = ?,
                directory = ?,
                deleted = FALSE
                WHERE directory = ? AND filename = ?;
        )");
        if (statement != nullptr) {
            sqlite3_bind_text(statement, 1, filename.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 2, extension.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 3, directory.c_str(), -1, SQLITE_STATIC);
            
            sqlite3_bind_text(statement, 4, old_directory.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 5, old_filename.c_str(), -1, SQLITE_STATIC);
            
            ExecuteStatement(statement);
        }
    }

    void AssetDatabase::DeleteAsset(std::string directory, std::string filename) {
        if (std::filesystem::is_directory(directory + filename)) {
            return;
        }

        std::filesystem::path file_path = std::filesystem::path(filename);

        std::string extension = file_path.extension().string();
        std::string relative_directory = normalizePath(std::filesystem::relative(directory, std::filesystem::current_path() / "assets").string());
    
        sqlite3_stmt* statement = CreateStatement("UPDATE assets SET deleted = TRUE WHERE filename = ? AND directory = ?;");
        if (statement != nullptr) {
            sqlite3_bind_text(statement, 1, filename.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(statement, 2, relative_directory.c_str(), -1, SQLITE_STATIC);

            ExecuteStatement(statement);
        }
    }

    void AssetDatabase::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) {

        std::string current_dir = m_WatchedDirectories[0];
        
        std::filesystem::path full_path = relative(std::filesystem::path(dir + filename), std::filesystem::path(current_dir));
        std::filesystem::path old_full_path = relative(std::filesystem::path(dir + oldFilename), std::filesystem::path(current_dir));

        switch ( action ) {
            case efsw::Actions::Add:
                InsertAsset(full_path);
                break;
            case efsw::Actions::Delete:
                DeleteAsset(dir, filename);
                break;
            case efsw::Actions::Modified:
                break;
            case efsw::Actions::Moved:
                UpdateAsset(full_path, old_full_path);
                break;
            default:
                ERROR("Asset Database: ", "Reached the default");
        }
    }

    void AssetDatabase::ScanFolder(std::string folderPath) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath)) {
            if (std::filesystem::is_directory(entry.path().string())) {
                continue;
            }

            if (std::filesystem::is_regular_file(entry)) {
                std::filesystem::path full_path = relative(entry.path(), std::filesystem::path(m_WatchedDirectories[0]));
                InsertAsset(full_path);
            }
        }

        sqlite3_stmt* statement = CreateStatement("UPDATE assets SET deleted = TRUE WHERE scanned = FALSE");
        if (statement != nullptr)
            ExecuteStatement(statement);

        ResetScans();
        Cleanup();
    }

    void AssetDatabase::Cleanup() {
        ExecuteQuery("DELETE FROM assets WHERE deleted = TRUE");
    }

    void AssetDatabase::ResetScans() {
        sqlite3_stmt* statement = CreateStatement("UPDATE assets SET scanned = FALSE WHERE scanned = TRUE");
        if (statement != nullptr)
            ExecuteStatement(statement);
    }

    sqlite3_stmt* AssetDatabase::CreateStatement(const char* sql) {
        int rc;
        sqlite3_stmt* stmt;
        rc = sqlite3_prepare_v2(m_AssetDb, sql, -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            ERROR("SQL error: ", sqlite3_errmsg(m_AssetDb));
            return nullptr;
        }

        return stmt;
    }

    void AssetDatabase::ExecuteStatement(sqlite3_stmt* stmt) {
        int rc;
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
            ERROR("SQL error: ", sqlite3_errmsg(m_AssetDb));
            sqlite3_finalize(stmt);
        } 
        sqlite3_finalize(stmt);
    }

    void AssetDatabase::ExecuteQuery(const char* sql) {
        char* zErrMsg = 0;

        int rc = sqlite3_exec(m_AssetDb, sql, callback, 0, &zErrMsg);

        if ( rc != SQLITE_OK) {
            ERROR("SQL error: ", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    std::string AssetDatabase::normalizePath(const std::string& pathString) {
        std::filesystem::path pathObj(pathString);
        pathObj.make_preferred();
        pathObj = pathObj.lexically_normal();
        if (!pathObj.empty() && pathObj.string().back() == std::filesystem::path::preferred_separator) {
            return pathObj.string().substr(0, pathObj.string().size() - 1);
        }
        return pathObj.string();
    }
}