#include "glfw.hpp"

#include <glm/fwd.hpp>
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

void GlfwInputApi::update(Action* action) {
    Input* input = Input::getInstance();

    void* window_handle = input->window->get_window_handle().get();
    GLFWwindow* window = reinterpret_cast<GLFWwindow*>(window_handle);
    unsigned int current_mods = glfw_get_modifiers(window);

    if(glfwGetKey(window, action->binding) == GLFW_PRESS && action->modifiers == current_mods) {
        action->just_pressed = (action->is_pressed == false) && !action->just_pressed;
        action->is_pressed = true;
    } else {
        action->just_released = (action->is_pressed == true) && !action->just_released;
        action->is_pressed = false;
    }


    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    

    input->mouse_delta = glm::vec2{ input->mouse_position.x - xpos, input->mouse_position.y - ypos };
    input->mouse_position = glm::vec2{ xpos, ypos };
}
