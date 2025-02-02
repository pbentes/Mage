#pragma once

#include <cstdint>
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

typedef struct ShaderAPI ShaderAPI;

typedef struct shader {
    char* name = nullptr;
    char* vertex_source = nullptr;
    char* fragment_source = nullptr;
    std::vector<uint32_t> vertex_bin;
    std::vector<uint32_t> fragment_bin;
    
    ShaderAPI* api = nullptr;
    void* data = nullptr; // Dynamic data specific to a graphics API
} shader;

void shader_load_vertex(shader* s, const char* vertexSourcePath); // Loads the vertex shader source
void shader_load_fragment(shader* s, const char* fragmentSourcePath); // Loads the fragment shader source
void shader_compile(shader* s); // Compile sources to SPIRV Binary modules
void shader_save_bin(shader* s, char* destination);

typedef struct ShaderAPI {
    void (*compile)(shader* shader) = nullptr; // Compile SPIRV binary modules to the apropriate format for the graphics API using SPIRV Cross
    void (*use)(shader* shader) = nullptr;
    void (*cleanup)(shader* shader) = nullptr;

    // Set uniforms
    void (*setBool)(shader* shader, const char* name, bool value) = nullptr;
    void (*setInt)(shader* shader, const char* name, int value) = nullptr;
    void (*setFloat)(shader* shader, const char* name, float value) = nullptr;
    void (*setMat4)(shader* shader, const char* name, glm::mat4 value) = nullptr;
} ShaderAPI;
