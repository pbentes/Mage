#pragma once

#include "../../interfaces/input.hpp"
#include "../../window/window.hpp"

#include <GLFW/glfw3.h>

unsigned int glfw_get_modifiers(GLFWwindow* window) {
    unsigned int mods = 0;

    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || 
        glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS) {
        mods |= GLFW_MOD_SHIFT;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS || 
        glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS) {
        mods |= GLFW_MOD_CONTROL;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS || 
        glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS) {
        mods |= GLFW_MOD_ALT;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS || 
        glfwGetKey(window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS) {
        mods |= GLFW_MOD_SUPER;
    }

    return mods;
}

void glfw_update_action(WindowHandle window_handle, Action* action) {
    GLFWwindow* window = (GLFWwindow*)get_native_window(window_handle);
    unsigned int current_mods = glfw_get_modifiers(window);

    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && action->modifiers == current_mods) {
        action->just_pressed = (action->is_pressed == false) && !action->just_pressed;
        action->is_pressed = true;
    } else {
        action->just_released = (action->is_pressed == true) && !action->just_released;
        action->is_pressed = false;
    }
}
