#pragma once

#include <memory>
#include <string>

class Window {
    public:
        Window(std::string title, int width, int height);
        Window(const Window&) = delete;
        ~Window();

        /* The methods below directly call the methods in the window interface */
        void close();
        void poll_events();
        void swap_buffers();
        bool should_close();

        std::shared_ptr<void> get_window_handle();

    private:
        std::shared_ptr<void> window_handle;
};

class WindowInterface {
    public:
        virtual std::shared_ptr<void> create_window(std::string title, int width, int height) = 0;
        virtual void close_window(Window* window) = 0;
        virtual void poll_events(Window* window) = 0;
        virtual void swap_buffers(Window* window) = 0;
        virtual bool should_close(Window* window) = 0;
};

void use_window_interface(WindowInterface* window_interface);
