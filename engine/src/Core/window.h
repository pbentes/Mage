#pragma once

#include "../interfaces/renderer.h"
#include "../interfaces/window.h"

////////////////////////////////
//~ pgb: Window

WindowAPI* GetWindowAPI(std::string api);
void SetWindowAPI(std::string api_name, WindowAPI api);

typedef struct Window {
    WindowAPI* api;
    RendererAPI* renderer;
    void* window_handle;
} Window;
