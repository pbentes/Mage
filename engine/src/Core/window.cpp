#include "window.h"

#include <map>

std::map<std::string, WindowAPI> WindowAPIs;

WindowAPI* GetWindowAPI(std::string api) {
    return &WindowAPIs[api];
}

void SetWindowAPI(std::string api_name, WindowAPI api) {
    WindowAPIs[api_name] = api;
}