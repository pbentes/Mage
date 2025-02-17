#include "window.hpp"

#include "../debug/logger.hpp"

#include <cstdlib>
#include <memory>

std::unique_ptr<WindowInterface> window_api = nullptr;

void use_window_interface(std::unique_ptr<WindowInterface> window_interface) {
    window_api = std::move(window_interface);
}

Window::Window(std::string title, int width, int height) {
    if(window_api == nullptr) {
        ERROR("No window api has been selected");
        exit(1);
    }

    window_handle = window_api->create_window(title, width, height);
}

Window::~Window() {
    //window_api->shutdown(std::make_shared<Window>(this));
}

void Window::close() {
    window_api->close_window(std::shared_ptr<Window>(this));
}

void Window::poll_events() {
    window_api->poll_events(std::shared_ptr<Window>(this));
}

void Window::swap_buffers() {
    window_api->swap_buffers(std::shared_ptr<Window>(this));
}

bool Window::should_close() {
    return window_api->should_close(std::shared_ptr<Window>(this));
}
