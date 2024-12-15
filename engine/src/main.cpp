#include "core/application.h"
#include "core/window/window_raylib.h"

#include <iostream>

int main() {
    ApplicationSettings app_settings = {
        .window_api = "RaylibWindowAPI",
        .window_title = "First Mage Window",
        .window_width = 800,
        .window_height = 450
    };

    std::cout << app_settings_serialize(&app_settings) << std::endl;
    
    // Create Window APIs
    CreateRaylibWindowAPI();

    // Create Renderer APIs

    Application app = app_init(&app_settings);
    app_run(&app);
    app_cleanup(&app);
}