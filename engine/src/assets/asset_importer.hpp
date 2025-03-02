#pragma once

#include "asset.hpp"

#include <memory>
#include <string>

class AssetImporter {
    public:
        virtual std::shared_ptr<Asset> import(std::string path) = 0;
};
