#include "filesystem_watcher.hpp"
#include "asset_database.hpp"

#include <debug/logger.hpp>

#include <filesystem>

FilesystemWatcher::FilesystemWatcher(std::vector<std::string> directories) {
    m_WatchedDirectories = directories;
    long i = 0;
    for (std::string& directory: m_WatchedDirectories) {
        INFO(directory);

        m_WatchIds[m_FileWatcher.addWatch(directory, this, true)] = i;
        scan_folder(directory);
    }

    m_FileWatcher.watch();
}

FilesystemWatcher::~FilesystemWatcher() {
    for (std::pair<const long, int> watchId: m_WatchIds) {
        m_FileWatcher.removeWatch(watchId.first);
    }
}

void FilesystemWatcher::scan_folder(std::string folderPath) {
    for (const auto& entry : std::filesystem::recursive_directory_iterator(folderPath)) {
        if (std::filesystem::is_directory(entry.path().string())) {
            continue;
        }

        if (std::filesystem::is_regular_file(entry)) {
            std::filesystem::path full_path = relative(entry.path(), std::filesystem::path(m_WatchedDirectories[0]));
            INFO(full_path);
        }
    }
}

void FilesystemWatcher::handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) {
    std::string current_dir = m_WatchedDirectories[m_WatchIds[watchid]]; // Get the root watched directory
    
    std::filesystem::path full_path = relative(std::filesystem::path(dir + filename), std::filesystem::path(current_dir));
    std::filesystem::path old_full_path = relative(std::filesystem::path(dir + oldFilename), std::filesystem::path(current_dir));

    AssetDatabase* asset_database = AssetDatabase::getInstance();

    switch ( action ) {
        case efsw::Actions::Add:
            // If file is in deleted stack restore file from tmp directory
            // Else Create toml
            asset_database->CreateAsset(full_path);
            break;
        case efsw::Actions::Delete:            
            // Move toml file to tmp
            asset_database->DeleteAsset(full_path);
            break;
        case efsw::Actions::Modified:
            if(std::filesystem::is_directory(full_path)) {
                return;
            }
            // Reimport file
            asset_database->ModifiedAsset(full_path);
            break;
        case efsw::Actions::Moved:
            // Move toml file
            asset_database->MovedAsset(full_path, old_full_path);
            break;
        default:
            ERROR("Filesystem Watcher: ", "Reached the default");
    }
}
