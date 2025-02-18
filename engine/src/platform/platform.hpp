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
        Platform() = default;
        Platform(const Platform& platform) = delete;
        static Platform* getInstance();

    public:
        ApplicationInterface* application_interface;
        WindowInterface* window_interface;
        InputInterface* input_interface;
        RendererInterface* renderer_interface;
        ShaderInterface* shader_interface;
    
    private:
        static Platform* instancePtr;
};
