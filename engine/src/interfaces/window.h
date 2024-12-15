#pragma once

#include <string>

typedef struct Window Window;

typedef struct WindowAPI {
    Window (*create)(int, int, std::string);
    void   (*close)(Window*);
    bool   (*should_close)(Window*);
    bool   (*is_ready)(Window*);
    bool   (*is_fullscreen)(Window*);
    bool   (*is_hidden)(Window*);
    bool   (*is_minimized)(Window*);
    bool   (*is_maximized)(Window*);
    bool   (*is_focused)(Window*);
    bool   (*is_resized)(Window*);
    void   (*toggle_fullscreen)(Window*);
    void   (*toggle_borderless)(Window*);
    void   (*maximize)(Window*);
    void   (*minimize)(Window*);
    void   (*restore)(Window*);
    void   (*set_icon)(Window*, void*); // Todo: Create an Image type
    void   (*set_title)(Window*, std::string);
    void   (*set_position)(int x, int y);
    void   (*set_monitor)(int monitor);
    void   (*set_minSize)(int width, int height);
    void   (*set_maxSize)(int width, int height);
    void   (*set_size)(int width, int height);
    void   (*set_opacity)(float opacity);
    void   (*set_focused)(void);
    void*  (*get_handle)(void);
} WindowAPI;

#include "../core/window.h"