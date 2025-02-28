#pragma once

#include <string>

class Serializable {
    public:
        // Serializes the current object into a toml file at the given path
        virtual void serialize(std::string path) = 0;
        // Deserialized the toml file at the given path into the current object
        virtual void deserialize(std::string path) = 0;
};
