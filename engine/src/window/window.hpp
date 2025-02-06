#pragma once

#include <Handles.hpp>

typedef handle WindowHandle;
typedef struct WindowAPI WindowAPI;

typedef struct window {
    void* native_window_handle = nullptr;
    WindowAPI* api = nullptr;
} window;

void* get_native_window(WindowHandle handle);
WindowHandle create_window(const char* title, int width, int height, WindowAPI* api);
