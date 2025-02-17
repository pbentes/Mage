#include "glfw.hpp"

#include "../../debug/logger.hpp"

#include <GLFW/glfw3.h>

#include <cstdlib>
#include <memory>

std::shared_ptr<void> GlfwWindowApi::create_window(std::string title, int width, int height) {
    const GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL) 
    {
        ERROR("Failed to create GLFW window");
        glfwTerminate();
        exit(-1);
    }
    
    return std::shared_ptr<void>(const_cast<GLFWwindow*>(window), [](void* ptr) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(ptr));
    });
}

void GlfwWindowApi::close_window(std::shared_ptr<Window> window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    glfwSetWindowShouldClose(glfw_window, true);
}

void GlfwWindowApi::poll_events(std::shared_ptr<Window> window) {
    glfwPollEvents();
}

void GlfwWindowApi::swap_buffers(std::shared_ptr<Window> window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    glfwSwapBuffers(glfw_window);
}

bool GlfwWindowApi::should_close(std::shared_ptr<Window> window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    return glfwWindowShouldClose(glfw_window);
}
