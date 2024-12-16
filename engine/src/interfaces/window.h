#pragma once

#include <string>

typedef struct Window Window;

typedef struct WindowAPI {
    Window (*create)(int width, int height, std::string title);
    void   (*close)(Window* window);
    bool   (*should_close)(Window* window);
    bool   (*is_ready)(Window* window);
    bool   (*is_fullscreen)(Window* window);
    bool   (*is_hidden)(Window* window);
    bool   (*is_minimized)(Window* window);
    bool   (*is_maximized)(Window* window);
    bool   (*is_focused)(Window* window);
    bool   (*is_resized)(Window* window);
    void   (*toggle_fullscreen)(Window* window);
    void   (*toggle_borderless)(Window* window);
    void   (*maximize)(Window* window);
    void   (*minimize)(Window* window);
    void   (*restore)(Window* window);
    void   (*set_icon)(Window* window, void* image); // Todo: Create an Image type
    void   (*set_title)(Window* window, std::string title);
    void   (*set_position)(Window* window, int x, int y);
    void   (*set_monitor)(Window* window, int monitor);
    void   (*set_min_size)(Window* window, int width, int height);
    void   (*set_max_size)(Window* window, int width, int height);
    void   (*set_size)(Window* window, int width, int height);
    void   (*set_opacity)(Window* window, float opacity);
    void   (*set_focused)(Window* window);
    void*  (*get_handle)(Window* window);
} WindowAPI;

#include "../core/window.h"