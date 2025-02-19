#include "input/input.hpp"
#include "platform/input/glfw.hpp"
#include "renderer/renderer.hpp"

#include <core/uuid.hpp>
#include <core/window.hpp>
#include <debug/logger.hpp>
#include <platform/application/glfw.hpp>
#include <platform/window/glfw.hpp>
#include <platform/renderer/opengl33.hpp>
#include <platform/platform.hpp>

#include <glm/glm.hpp>
#include <glm/vec4.hpp>

int main() {
    Uuid64 uuid;

    GlfwApplicationApi app_api;
    GlfwWindowApi window_api;
    OpenGl33 opengl_api;
    GlfwInputApi input_api;

    Platform* platform = Platform::getInstance();
    platform->application_interface = reinterpret_cast<ApplicationInterface*>(&app_api);
    platform->window_interface = reinterpret_cast<WindowInterface*>(&window_api);
    platform->renderer_interface = reinterpret_cast<RendererInterface*>(&opengl_api);
    platform->input_interface = reinterpret_cast<InputInterface*>(&input_api);
    
    app_api.init();

    opengl_api.init();

    Window window("Mage Runtime", 800, 600);

    opengl_api.load();

    Action action("", KEY_SPACE, 0);
    Input::getInstance()->window = &window;

    while(!window.should_close()) {
        Input::getInstance()->update();

        opengl_api.clear(glm::vec4 {0.0588f, 0.0588f, 0.0588f, 1.0f});
        
        if(action.just_pressed)
            INFO("Hello input");

        window.swap_buffers();
        window.poll_events();
    }

    app_api.deinit();
}
