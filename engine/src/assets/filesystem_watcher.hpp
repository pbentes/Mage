#pragma once

#include <efsw/efsw.hpp>

#include <unordered_map>

class FilesystemWatcher: public efsw::FileWatchListener {
    public:
        FilesystemWatcher(std::vector<std::string> directories);
        ~FilesystemWatcher();
    
        void handleFileAction(efsw::WatchID watchid, const std::string& dir, const std::string& filename, efsw::Action action, std::string oldFilename) override;
        void scan_folder(std::string folder_path);
        
    private:
        std::vector<std::string> m_WatchedDirectories;
        std::unordered_map<efsw::WatchID, int> m_WatchIds;
        efsw::FileWatcher m_FileWatcher;
};
