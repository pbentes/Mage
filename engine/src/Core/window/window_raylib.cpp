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

bool RaylibIsReady(Window* window) {
    return IsWindowReady();
}

bool RaylibIsFullScreen(Window* window) {
    return IsWindowFullscreen();
}

bool RaylibIsHidden(Window* window) {
    return IsWindowHidden();
}

bool RaylibIsMinimized(Window* window) {
    return IsWindowMinimized();
}

bool RaylibIsMaximized(Window* window) {
    return IsWindowMaximized();
}

bool RaylibIsFocused(Window* window) {
    return IsWindowFocused();
}

bool RaylibIsResized(Window* window) {
    return IsWindowResized();
}

void RaylibToggleFullscreen(Window* window) {
    return ToggleFullscreen();
}

void RaylibToggleBorderless(Window* window) {
    ToggleBorderlessWindowed();
}

void RaylibMaximize(Window* window) {
    MaximizeWindow();
}

void RaylibMinimize(Window* window) {
    MinimizeWindow();
}

void RaylibRestore(Window* window) {
    RestoreWindow();
}

void RaylibSetIcon(Window* window, void* image) {
    SetWindowIcon((Image)image);
}

void RaylibSetTitle(Window* window, std::string title) {
    SetWindowTitle(title.c_str());
}

void RaylibSetPosition(Window* window, int x, int y) {
    SetWindowPosition(x, y);
}

void RaylibSetMonitor(Window* window, int monitor) {
    SetWindowMonitor(monitor);
}

void RaylibSetMinSize(Window* window, int x, int y) {
    SetWindowMinSize(x, y);
}

void RaylibSetMaxSize(Window* window, int x, int y) {
    SetWindowMaxSize(x, y);
}

void RaylibSetSize(Window* window, int x, int y) {
    SetWindowSize(x, y);
}

void RaylibSetOpacity(Window* window, float opacity) {
    SetWindowOpacity(opacity);
}

void RaylibSetFocused(Window* window) {
    SetWindowFocused();
}

void* RaylibGetHandle(Window* window) {
    return GetWindowHandle();
}

void CreateRaylibWindowAPI() {
    SetWindowAPI("RaylibWindowAPI", WindowAPI {
        .create = RaylibCreateWindow,
        .close = RaylibCloseWindow,
        .should_close = RaylibShouldCloseWindow,
        .is_ready = RaylibIsReady,
        .is_fullscreen = RaylibIsFullScreen,
        .is_hidden = RaylibIsHidden,
        .is_minimized = RaylibIsMinimized,
        .is_maximized = RaylibIsMaximized,
        .is_focused = RaylibIsFocused,
        .is_resized = RaylibIsResized,
        .toggle_fullscreen = RaylibToggleFullscreen,
        .toggle_borderless = RaylibToggleBorderless,
        .maximize = RaylibMaximize,
        .minimize = RaylibMinimize,
        .restore = RaylibRestore,
        .set_icon = RaylibSetIcon,
        .set_title = RaylibSetTitle,
        .set_position = RaylibSetPosition,
        .set_monitor = RaylibSetMonitor,
        .set_min_size = RaylibSetMinSize,
        .set_max_size = RaylibSetMaxSize,
        .set_size = RaylibSetSize,
        .set_opacity = RaylibSetOpacity,
        .set_focused = RaylibSetFocused,
        .get_handle = RaylibGetHandle
    });
}