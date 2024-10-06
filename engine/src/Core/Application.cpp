#include "Application.h"

#include "../Debug/Instrumentor.h"
#include "../Renderer/Renderer.h"

#include <memory>
#include <raylib.h>

namespace Engine {
    Application::Application() {
        Instrumentor::Get().BeginSession("Engine");
    }

    Application::~Application() {}

    void Application::run() {
        PROFILE_SCOPE("Application Loop");
        Renderer render;

        render.init();

        while (!WindowShouldClose())
        {
            render.update(GetFrameTime());
        }
    }
}