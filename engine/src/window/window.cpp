#include "window.hpp"
#include "Handles.hpp"

HandleStore window_handles = handleStoreCreate(sizeof(window), 10);

void* get_native_window(WindowHandle handle) {
    return handleStoreGet(&window_handles, handle);
}

WindowHandle create_window(const char* title, int width, int height, WindowAPI* api) {
    window _window = window {
        .native_window_handle = nullptr,
        .api = api
    };
    return handleStoreAdd(&window_handles, &_window);
}
