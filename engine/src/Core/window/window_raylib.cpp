#include "window_raylib.h"
#include "interfaces/window.h"
#include "../window.h"

#include <raylib.h>

Window RaylibCreateWindow(int width, int height, std::string title) {
    InitWindow(width, height, title.c_str());

    return Window {
        .api = GetWindowAPI("RaylibWindowAPI"),
        .window_handle = nullptr
    };
}

void RaylibCloseWindow(Window* window) {
    CloseWindow();
}

bool RaylibShouldCloseWindow(Window* window) {
    return WindowShouldClose();
}

void CreateRaylibWindowAPI() {
    SetWindowAPI("RaylibWindowAPI", WindowAPI {
        .create = RaylibCreateWindow,
        .close = RaylibCloseWindow,
        .should_close = RaylibShouldCloseWindow
    });
}