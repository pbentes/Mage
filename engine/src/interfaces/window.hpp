#pragma once

#include "../window/window.hpp"
#include <glm/vec2.hpp>

typedef struct WindowAPI {
    int (*initialize)(void) = nullptr;
    void (*shutdown)(void) = nullptr;
    void* (*create_window)(const char* title, int width, int height) = nullptr;
    void (*close_window)(window* _window) = nullptr;
    void (*poll_events)(void) = nullptr;
    void (*swap_buffers)(window* _window) = nullptr;
    void (*set_window_size)(window* _window, int width, int height) = nullptr;
    glm::ivec2 (*get_window_size)(window* _window) = nullptr;
    bool (*should_close)(window* _window) = nullptr;
} WindowAPI;
