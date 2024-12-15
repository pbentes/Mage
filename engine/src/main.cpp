#include "core/application.h"

#include <iostream>

int main() {
    Application::ApplicationSettings app_settings = {
        .title = "",
        .window_width = 800,
        .window_height = 450
    };

    Application::Application app = Application::app_init(&app_settings);

    Application::app_run(&app);

    std::cout << "Hello mage!" << std::endl;
}