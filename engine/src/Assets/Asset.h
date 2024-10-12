#pragma once

#include <cstddef>
#include <string>

namespace Engine {
    class Asset {
        public:
            Asset(size_t id, std::string path, std::string directory, std::string extension, bool deleted);
            ~Asset() = default;

            std::string ToString() const;
            std::string GetPath();
        private:
            size_t m_Id;
            std::string m_Directory;
            std::string m_Extension;
            bool m_Deleted;
            std::string m_Path;
    };
}