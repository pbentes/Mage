#include "core/application.h"

#include <iostream>

int main() {
    ApplicationSettings app_settings = {
        .title = "",
        .window_width = 800,
        .window_height = 450
    };

    Application app = app_init(&app_settings);

    app_run(&app);

    std::cout << "Hello mage!" << std::endl;
}