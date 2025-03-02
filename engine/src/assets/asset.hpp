#pragma once

#include "../core/serializable.hpp"

class Asset: Serializable {
    public:
        void load();
        bool is_loaded();
    
    private:
        bool loaded;
    
    public:
        void* imported_asset;
};
