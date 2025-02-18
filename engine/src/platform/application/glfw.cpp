#include "glfw.hpp"

#include <GLFW/glfw3.h>

void GlfwApplicationApi::init() {
    glfwInit();
}

void GlfwApplicationApi::deinit() {
    glfwTerminate();
}
