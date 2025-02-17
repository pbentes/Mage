#pragma once

#include "../core/application.hpp"
#include "../core/window.hpp"
#include "../input/input.hpp"
#include "../renderer/renderer.hpp"
#include "../renderer/shader.hpp"

#include <memory>
#include <mutex>

class Platform {
    public:
        Platform() = default;\
        Platform(const Platform& platform) = delete;
        static Platform* getInstance();

    public:
        std::shared_ptr<ApplicationInterface> application_interface;
        std::shared_ptr<WindowInterface> window_interface;
        std::shared_ptr<InputInterface> input_interface;
        std::shared_ptr<RendererInterface> renderer_interface;
        std::shared_ptr<ShaderInterface> shader_interface;
    
    private:
        static Platform* instancePtr;
        static std::mutex mtx;
};
