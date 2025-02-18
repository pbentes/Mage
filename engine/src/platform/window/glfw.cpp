#include "glfw.hpp"

#include "../../debug/logger.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <memory>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

std::shared_ptr<void> GlfwWindowApi::create_window(std::string title, int width, int height) {
    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL) 
    {
        ERROR("Failed to create GLFW window");
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    return std::shared_ptr<void>(const_cast<GLFWwindow*>(window), [](void* ptr) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(ptr));
    });
}

void GlfwWindowApi::close_window(Window* window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    glfwSetWindowShouldClose(glfw_window, true);
}

void GlfwWindowApi::poll_events(Window* window) {
    glfwPollEvents();
}

void GlfwWindowApi::swap_buffers(Window* window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    glfwSwapBuffers(glfw_window);
}

bool GlfwWindowApi::should_close(Window* window) {
    GLFWwindow* glfw_window = std::static_pointer_cast<GLFWwindow>(window->get_window_handle()).get();
    return glfwWindowShouldClose(glfw_window);
}
