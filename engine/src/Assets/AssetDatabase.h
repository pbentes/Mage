#pragma once

#include <efsw/efsw.hpp>
#include <sqlite3.h>

#include <cstddef>
#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "Asset.h"

namespace Engine {
    class AssetDatabase : public efsw::FileWatchListener {
        public:
            AssetDatabase(std::vector<std::string> directories);
            ~AssetDatabase();
            
            // <WatchedFolderName>://path/to/file.txt
            std::shared_ptr<Asset> GetAsset(std::string resourcePath);
            std::vector<size_t> GetAssetsQuery(std::string query, std::vector<std::string> args);

            void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) override;

        private:
            friend int callback(void* NotUsed, int argc, char** argv, char** azColName);
            
            // Inserts a new asset into the database. If the asset already exists but is marked for deletion it unmarks said asset.
            void InsertAsset(std::filesystem::path full_path);
            void UpdateAsset(std::filesystem::path full_path, std::filesystem::path old_full_path);

            // Marks an asset for deletion
            void DeleteAsset(std::string directory, std::string filename);

            // Scan a folder on startup
            void ScanFolder(std::string folderPath);
            void ResetScans();
            
            // Deletes all assets marked for deletion
            void Cleanup();

            sqlite3_stmt* CreateStatement(const char* sql);
            void ExecuteStatement(sqlite3_stmt* stmt);
            void ExecuteQuery(const char* sql);

            std::string normalizePath(const std::string& pathString);
            
        private:
            std::vector<std::string> m_WatchedDirectories;
            std::unordered_map<efsw::WatchID, int> m_WatchIds;
            sqlite3* m_AssetDb;
            efsw::FileWatcher m_FileWatcher;
            std::unordered_map<size_t, std::shared_ptr<Asset>> m_AssetCache;
    };
}