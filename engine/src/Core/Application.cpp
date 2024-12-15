#include "application.h"
#include "toml/serializer.hpp"

#include <raylib.h>
#include <toml.hpp>

////////////////////////////////
//~ pgb: Application

std::string app_settings_serialize(ApplicationSettings* app_settings) {
    toml::value value(toml::table {
        {"title", toml::string{ app_settings->title }},
        {"window_width", toml::integer{ app_settings->window_width }},
        {"window_height", toml::integer{ app_settings->window_height }},
    });

    return toml::format(value);
}

ApplicationSettings app_settings_deserialize(std::string path) {
    const toml::value app_settings = toml::parse(path);

    return ApplicationSettings {
        .title = toml::find<std::string>(app_settings, "title").c_str(),
        .window_width = toml::find<int>(app_settings, "window_width"),
        .window_height = toml::find<int>(app_settings, "window_height")
    };
}

////////////////////////////////
//~ pgb: Application

Application app_init(ApplicationSettings* app_settings) {
    return Application {
        .application_settings     = app_settings,
        .application_should_close = false
    };
}

void app_run(Application* app) {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(main_loop, app, 0, 1);
#else
    while (!app->application_should_close)
    {
        app_loop(app);
    }
#endif
}

void app_loop(Application* app) {
    app_close(app);
}

void app_close(Application* app) {
    app->application_should_close = true;
}

void app_cleanup(Application* app) {
    
}