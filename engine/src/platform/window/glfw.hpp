#pragma once

#include "../../core/window.hpp"

class GlfwWindowApi: WindowInterface {
    public:
        std::shared_ptr<void> create_window(std::string title, int width, int height) override;
        void close_window(std::shared_ptr<Window> window) override;
        void poll_events(std::shared_ptr<Window> window) override;
        void swap_buffers(std::shared_ptr<Window> window) override;
        bool should_close(std::shared_ptr<Window> window) override;
};
