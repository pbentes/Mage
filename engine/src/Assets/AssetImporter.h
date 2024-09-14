#pragma once

#include <filesystem>
#include <memory>
#include <vector>

namespace Engine {
    class IAssetImporter {
        public:
            IAssetImporter() = default;
            ~IAssetImporter() = default;
            virtual std::shared_ptr<std::vector<std::byte>> ImportAsset(std::filesystem::path assetPath) = 0;
    };
}