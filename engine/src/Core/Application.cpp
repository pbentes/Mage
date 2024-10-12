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

    void Application::CloseApplication() {
        ApplicationShouldClose = true;
    }

    void Application::run() {
        PROFILE_SCOPE("Application Loop");
        Renderer render(this);

        render.init();

        while (!ApplicationShouldClose)
        {
            render.update(GetFrameTime());
        }
    }
}