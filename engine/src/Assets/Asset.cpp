#include "Asset.h"

#include <cstddef>

namespace Engine {
    Asset::Asset(size_t id, std::string path, std::string directory, std::string extension, bool deleted): m_Id(id), m_Path(path), m_Directory(directory), m_Extension(extension), m_Deleted(deleted) {}

    std::string Asset::GetPath() {
        return m_Path;
    }
}