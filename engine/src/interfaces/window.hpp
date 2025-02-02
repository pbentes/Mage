#pragma once

#include <glm/vec2.hpp>

typedef struct WindowAPI {
    int (*initialize)(void) = nullptr;
    void (*shutdown)(void) = nullptr;
    void* (*create_window)(const char* title, int width, int height) = nullptr;
    void (*close_window)(void* window_handle) = nullptr;
    void (*poll_events)(void) = nullptr;
    void (*swap_buffers)(void* window_handle) = nullptr;
    void (*set_resize_callback)(void* window_handle, void (*callback)(int width, int height)) = nullptr;
    void (*set_window_size)(void* window_handle, int* width, int* height) = nullptr;
    glm::ivec2 (*get_window_size)(void* window_handle) = nullptr;
    bool (*should_close)(void* window_handle) = nullptr;
} WindowAPI;
