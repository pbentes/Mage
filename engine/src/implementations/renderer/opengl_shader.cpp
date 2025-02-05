#include "opengl_shader.hpp"

#include "../../debug/logger.hpp"

#include <cstdlib>
#include <glad/gl.h>
#include <glm/gtc/type_ptr.hpp>
#include <spirv_glsl.hpp>


typedef struct OpenGLData {
    unsigned int program;
} OpenGLData;

void openglShaderCompile(shader* _shader) {
    spirv_cross::CompilerGLSL glslVertexCompiler(_shader->vertex_bin);
    spirv_cross::CompilerGLSL glslFragmentCompiler(_shader->fragment_bin);

    spirv_cross::CompilerGLSL::Options options;
    options.version = 330;
    options.es = false;

    glslVertexCompiler.set_common_options(options);
    glslFragmentCompiler.set_common_options(options);

    std::string vertexSourceString = glslVertexCompiler.compile();
    std::string fragmentSourceString = glslFragmentCompiler.compile();

    const char* vertexSource = vertexSourceString.c_str();
    const char* fragmentSource = fragmentSourceString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    int  success;
    char infoLog[512];

    { // Compile Vertex Shader
        glShaderSource(vertexShader, 1, &vertexSource, NULL);

        glCompileShader(vertexShader);

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n", infoLog);
        }
    }
    
    { // Compile Fragment Shader
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n", infoLog);
        }
    }

    { // Link Program
        unsigned int program = glCreateProgram();
        ((OpenGLData*)_shader->data)->program = program;

        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n", infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
}

void openglShaderUse(shader* _shader) {
    glUseProgram(((OpenGLData*)_shader->data)->program);
}

void openflShaderCleanup(shader* _shader) {
    free(_shader->api);
    free(_shader->data);
}

void openglShaderSetBool(shader* _shader, const char* name, bool value) {
    glUniform1i(glGetUniformLocation(((OpenGLData*)_shader->data)->program, name), (int)value); 
}

void openglShaderSetInt(shader* _shader, const char* name, int value) {
    glUniform1i(glGetUniformLocation(((OpenGLData*)_shader->data)->program, name), value);
}

void openglShaderSetFloat(shader* _shader, const char* name, float value) {
    glUniform1f(glGetUniformLocation(((OpenGLData*)_shader->data)->program, name), value);
}

void openglShaderSetMat4(shader* _shader, const char* name, glm::mat4 value) {
    unsigned int location = glGetUniformLocation(((OpenGLData*)_shader->data)->program, name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}

shader* shader_opengl(shader* _shader) {
    if(_shader == nullptr)
        return nullptr;

    _shader->api = (ShaderAPI*)malloc(sizeof(ShaderAPI));
    _shader->data = (OpenGLData*)malloc(sizeof(OpenGLData));
    
    *_shader->api = ShaderAPI {
        .compile = openglShaderCompile,
        .use = openglShaderUse,
        .cleanup = openflShaderCleanup,
        .setBool = openglShaderSetBool,
        .setInt = openglShaderSetInt,
        .setFloat = openglShaderSetFloat,
        .setMat4 = openglShaderSetMat4,
    };

    return _shader;
}
