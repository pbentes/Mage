#include "glfw_window.hpp"

#include "../../interfaces/window.hpp"
#include <cstdlib>

int glfw_initialize(void) {
    return 1;
}

void glfw_shutdown(void) {

}

void* glfw_create_window(const char* title, int width, int height) {
    return nullptr;
}

void glfw_close_window(window* _window) {

}

void glfw_poll_events(void) {

}

void glfw_swap_buffers(window* _window) {

}

void glfw_set_window_size(window* _window, int width, int height) {

}

glm::ivec2 glfw_get_window_size(window* _window) {
    return glm::ivec2 {0, 0};
}

bool glfw_should_close(window* _window) {
    return false;
}

void windowGlfw(window* _window) {
    _window->api = (WindowAPI*)malloc(sizeof(WindowAPI));
    *_window->api = WindowAPI {
        .initialize = glfw_initialize,
        .shutdown = glfw_shutdown,
        .create_window = glfw_create_window,
        .close_window = glfw_close_window,
        .poll_events = glfw_poll_events,
        .swap_buffers = glfw_swap_buffers,
        .set_window_size = glfw_set_window_size,
        .get_window_size = glfw_get_window_size,
        .should_close = glfw_should_close,
    };
}
