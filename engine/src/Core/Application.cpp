#include "application.h"
#include "interfaces/window.h"
#include "toml/serializer.hpp"
#include "window.h"

#include <cstdlib>
#include <raylib.h>
#include <toml.hpp>

////////////////////////////////
//~ pgb: Application

std::string app_settings_serialize(ApplicationSettings* app_settings) {
    toml::value value(toml::table {
        {"window_api", toml::string{ app_settings->window_api }},
        {"window_title", toml::string{ app_settings->window_title }},
        {"window_width", toml::integer{ app_settings->window_width }},
        {"window_height", toml::integer{ app_settings->window_height }},
    });

    return toml::format(value);
}

ApplicationSettings app_settings_deserialize(std::string path) {
    const toml::value app_settings = toml::parse(path);

    return ApplicationSettings {
        .window_api = toml::find<std::string>(app_settings, "window_api").c_str(),
        .window_title = toml::find<std::string>(app_settings, "window_title").c_str(),
        .window_width = toml::find<int>(app_settings, "window_width"),
        .window_height = toml::find<int>(app_settings, "window_height")
    };
}

////////////////////////////////
//~ pgb: Application

Application app_init(ApplicationSettings* app_settings) {
    Window* window = (Window*)malloc(sizeof(Window));
    
    *window = GetWindowAPI(app_settings->window_api)->create(app_settings->window_width, app_settings->window_height, app_settings->window_title);

    return Application {
        .application_settings     = app_settings,
        .application_should_close = false,
        .window = window
    };
}

void app_run(Application* app) {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(app_loop, app, 0, 1);
#else
    while (!app->window->api->should_close(app->window))
    {
        app_loop(app);
    }
#endif
}

void app_loop(Application* app) {
    BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}

void app_close(Application* app) {
    app->application_should_close = true;
}

void app_cleanup(Application* app) {
    app->window->api->close(app->window);
}