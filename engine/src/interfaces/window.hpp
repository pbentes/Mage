#pragma once

#include <glm/vec2.hpp>

typedef struct WindowAPI {
    int (*initialize)(void);
    void (*shutdown)(void);
    void* (*create_window)(const char* title, int width, int height);
    void (*close_window)(void* window_handle);
    void (*poll_events)(void);
    void (*swap_buffers)(void* window_handle);
    void (*set_resize_callback)(void* window_handle, void (*callback)(int width, int height));
    void (*set_window_size)(void* window_handle, int* width, int* height);
    glm::ivec2 (*get_window_size)(void* window_handle);
    bool (*should_close)(void* window_handle);
} WindowAPI;
