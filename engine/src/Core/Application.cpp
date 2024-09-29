#include "Application.h"

#include "../Debug/Instrumentor.h"
#include "../Renderer/Renderer.h"

#include <memory>
#include <raylib.h>

namespace Engine {
    Application::Application() {
        Instrumentor::Get().BeginSession("Engine");
        m_Registry = std::shared_ptr<entt::registry>(new entt::registry());
        m_Scheduler.attach<Renderer>(m_Registry);
    }

    Application::~Application() {}

    void Application::run() {
        PROFILE_SCOPE("Application Loop");

        while (WindowShouldClose())
        {
            m_Scheduler.update(GetFrameTime());
        }
    }
}