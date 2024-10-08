#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace Engine {
    class Asset {
        public:
            Asset(size_t id, std::string path, std::string directory, std::string extension, bool deleted);
            ~Asset() = default;

            void LoadAssetSync();
            void LoadAssetAsync();
            void StreamAsset(size_t startByte, size_t endByte);
            void UnloadAsset();

            std::string ToString() const;
        private:
            size_t m_Id;
            std::string m_Directory;
            std::string m_Extension;
            bool m_Deleted;
        public:
            std::shared_ptr<std::vector<std::byte>> m_Blob;
            std::string m_Path;
    };
}