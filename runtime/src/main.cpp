#include "renderer/renderer.hpp"
#include <core/uuid.hpp>
#include <cstdint>
#include <debug/logger.hpp>

#include <memory>
#include <platform/application/glfw.hpp>
#include <platform/window/glfw.hpp>
#include <platform/renderer/opengl33.hpp>
#include <core/window.hpp>
#include <platform/platform.hpp>

#include <glm/glm.hpp>
#include <glm/vec4.hpp>

int main() {
    Uuid64 uuid;

    GlfwApplicationApi app_api;
    GlfwWindowApi window_api;
    OpenGl33 opengl_api;

    Platform* platform = Platform::getInstance();
    platform->application_interface = reinterpret_cast<ApplicationInterface*>(&app_api);
    platform->window_interface = reinterpret_cast<WindowInterface*>(&window_api);
    platform->renderer_interface = reinterpret_cast<RendererInterface*>(&opengl_api);

    app_api.init();

    opengl_api.init();

    Window window("Window", 800, 600);

    opengl_api.load();

    while(!window.should_close()) {
        opengl_api.clear(glm::vec4 {0.0588f, 0.0588f, 0.0588f, 1.0f});
        window.swap_buffers();
        window.poll_events();
    }

    app_api.deinit();
}
