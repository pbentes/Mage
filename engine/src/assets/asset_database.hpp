#pragma once

#include "asset.hpp"

#include <filesystem>
#include <memory>
#include <unordered_map>
#include <string>

class AssetDatabase {
    public:
        AssetDatabase() = default;
        AssetDatabase(const AssetDatabase& platform) = delete;
        static AssetDatabase* getInstance();

        void CreateAsset(std::filesystem::path path);
        void DeleteAsset(std::filesystem::path path);
        void ModifiedAsset(std::filesystem::path path);
        void MovedAsset(std::filesystem::path new_path, std::filesystem::path old_path);

        std::shared_ptr<Asset> GetAssetAtPath(std::filesystem::path path);
        
    private:
        static AssetDatabase* instancePtr;

        std::unordered_map<std::string, std::shared_ptr<Asset>> m_Assets;
        std::vector<std::string> m_DeletedStack;
};
