#include <assets/filesystem_watcher.hpp>
#include <core/uuid.hpp>
#include <core/window.hpp>
#include <debug/logger.hpp>
#include <input/input.hpp>
#include <platform/application/glfw.hpp>
#include <platform/input/glfw.hpp>
#include <platform/platform.hpp>
#include <platform/renderer/opengl33.hpp>
#include <platform/window/glfw.hpp>
#include <renderer/renderer.hpp>

#include <glm/glm.hpp>
#include <glm/vec4.hpp>

#include <filesystem>

int main(int argc, char* argv[]) {
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

    Action fullscreen("fullscreen", KEY_ENTER, MOD_ALT);
    Action action("test", KEY_SPACE, 0);
    Action quit_action("quit", KEY_ESCAPE, 0);
    Input* input = Input::getInstance();
    input->window = &window;

    { // Watch project path
        std::string project_path = "";
        if (argc < 1) {
            project_path = std::filesystem::current_path().remove_filename().string();
        } else {
            std::filesystem::path p = std::filesystem::path(std::string(argv[1]));
            if(!std::filesystem::is_directory(p)) {
                p = p.remove_filename();
            }
            project_path = p.string();
        }
        FilesystemWatcher watcher(std::vector<std::string> { project_path });
    }

    window.fullscreen();

    while(!window.should_close()) {
        Input::getInstance()->update();

        opengl_api.clear(glm::vec4 {0.0588f, 0.0588f, 0.0588f, 1.0f});

        if(input->action("fullscreen")->just_pressed) {
            if(!window.is_fullscreen()) {
                window.fullscreen();
            } else {
                window.windowed();
            }
        }

        if(input->action("quit")->just_pressed) {
            window.close();
        }
        
        if(input->action("test")->just_pressed) {
            window.set_cursor_mode(CursorMode::Disabled);
        }

        window.swap_buffers();
        window.poll_events();
    }

    app_api.deinit();
}
