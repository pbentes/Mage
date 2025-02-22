#pragma once

#include "../../core/window.hpp"

class GlfwWindowApi: WindowInterface {
    public:
        std::shared_ptr<void> create_window(std::string title, int width, int height) override;
        void close_window(Window* window) override;
        void poll_events(Window* window) override;
        void swap_buffers(Window* window) override;
        bool should_close(Window* window) override;
        void set_cursor_mode(Window* window, CursorMode cursor_mode) override;
};
