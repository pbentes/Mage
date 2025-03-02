#include "asset_database.hpp"

AssetDatabase* AssetDatabase::instancePtr = nullptr;

AssetDatabase* AssetDatabase::getInstance() {
    if (instancePtr == nullptr) {
        if (instancePtr == nullptr) {
            instancePtr = new AssetDatabase();
        }
    }
    return instancePtr;
}

void AssetDatabase::CreateAsset(std::filesystem::path path) {
    std::string filename;
    std::string folder_path;
}

void AssetDatabase::DeleteAsset(std::filesystem::path path) {

}

void AssetDatabase::ModifiedAsset(std::filesystem::path path) {

}

void AssetDatabase::MovedAsset(std::filesystem::path new_path, std::filesystem::path old_path) {

}

std::shared_ptr<Asset> AssetDatabase::GetAssetAtPath(std::filesystem::path path) {
    return m_Assets[path.string()];
}
