#pragma once

#include "window.h"

#include <string>
#include <vector>

//////////////////////////////
//~ pgb: Application Settings

typedef struct ApplicationSettings {
    std::string title;
    int window_width;
    int window_height;
} ApplicationSettings;

std::string app_settings_serialize(ApplicationSettings* app_settings);
ApplicationSettings app_settings_deserialize(std::string path);

/////////////////////
//~ pgb: Application

typedef struct Application {
    ApplicationSettings* application_settings;
    bool application_should_close;
    std::vector<Window> windows;
} Application;

Application app_init(ApplicationSettings* app_settings);
void app_run(Application* app);
void app_loop(Application* app);
void app_close(Application* app);
void app_cleanup(Application* app);
