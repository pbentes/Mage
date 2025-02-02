#include "../interfaces/shader.hpp"

#include "../debug/logger.hpp"

#include <shaderc/shaderc.hpp>

#include <iostream>

std::vector<uint32_t> compile_file(const std::string& source_name, shaderc_shader_kind kind, const std::string& source, bool optimize = false) {
    shaderc::Compiler compiler;
    shaderc::CompileOptions options;

    if (optimize) options.SetOptimizationLevel(shaderc_optimization_level_size);

    shaderc::SpvCompilationResult module =
        compiler.CompileGlslToSpv(source, kind, source_name.c_str(), options);

    if (module.GetCompilationStatus() != shaderc_compilation_status_success) {
        std::cerr << module.GetErrorMessage();
        return std::vector<uint32_t>();
    }

    return { module.cbegin(), module.cend() };
}

void shader_load_vertex(shader* s, const char* vertexSourcePath) {
    std::ifstream outputFile;
    outputFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        outputFile.open(vertexSourcePath);
        std::stringstream outputStream;
        outputStream << outputFile.rdbuf();
        outputFile.close();
        s->vertex_source = (char*)outputStream.str().c_str();
    } catch(std::ifstream::failure& e) {
        ERROR("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }
}

void shader_load_fragment(shader* s, const char* fragmentSourcePath) {
    std::ifstream outputFile;
    outputFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        outputFile.open(fragmentSourcePath);
        std::stringstream outputStream;
        outputStream << outputFile.rdbuf();
        outputFile.close();
        s->fragment_source = (char*)outputStream.str().c_str();
    } catch(std::ifstream::failure& e) {
        ERROR("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }
}

void shader_compile(shader* s) {
    if(s->vertex_source != nullptr) {
        s->vertex_bin = compile_file(s->name, shaderc_shader_kind::shaderc_glsl_vertex_shader, s->vertex_source, true);
    } else {
        INFO("Vertex shader is not initialized");
    }

    if(s->fragment_source != nullptr) {
        s->fragment_bin = compile_file(s->name, shaderc_shader_kind::shaderc_glsl_fragment_shader, s->fragment_source, true);
    } else {
        INFO("Fragment shader is not initialized");
    }
}
