#include "window.hpp"

#include "../platform/platform.hpp"

#include <memory>

Window::Window(std::string title, int width, int height) {
    Platform* platform = Platform::getInstance();

    window_handle = platform->window_interface->create_window(title, width, height);
}

Window::~Window() {
    //window_api->shutdown(std::make_shared<Window>(this));
}

void Window::close() {
    Platform* platform = Platform::getInstance();
    platform->window_interface->close_window(this);
}

void Window::poll_events() {
    Platform* platform = Platform::getInstance();
    platform->window_interface->poll_events(this);
}

void Window::swap_buffers() {
    Platform* platform = Platform::getInstance();
    platform->window_interface->swap_buffers(this);
}

bool Window::should_close() {
    Platform* platform = Platform::getInstance();
    return platform->window_interface->should_close(this);
}

std::shared_ptr<void> Window::get_window_handle() {
    return this->window_handle;
}

void Window::set_cursor_mode(CursorMode cursor_mode) {
    Platform* platform = Platform::getInstance();
    platform->window_interface->set_cursor_mode(this, cursor_mode);
}
