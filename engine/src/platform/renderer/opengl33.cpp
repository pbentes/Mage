#include "opengl33.hpp"

#include "../../debug/logger.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/vec4.hpp>


void OpenGl33::init() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void OpenGl33::load() {
    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
    {
        ERROR("Failed to initialize GLAD");
    }
}

void OpenGl33::deinit() {}

void OpenGl33::clear(glm::vec4 color) {
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}
