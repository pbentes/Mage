#include "Application.h"

#include "../Debug/Instrumentor.h"
#include "../Renderer/Renderer.h"
#include "../Scripting/Scripting.h"

#include <memory>
#include <raylib.h>

namespace Engine {
    Application::Application() {
        Instrumentor::Get().BeginSession("Engine");
        m_Registry = std::shared_ptr<entt::registry>(new entt::registry());
        m_Scheduler.attach<Scripting>(m_Registry)
                   .attach<Renderer>(m_Registry);
    }

    Application::~Application() {
        Instrumentor::Get().EndSession();
    }

    void Application::run() {
        PROFILE_SCOPE("Application Loop");

        while (!m_Scheduler.empty())
        {
            if (WindowShouldClose()) {
                m_Scheduler.clear();
                continue;
            }
            
            m_Scheduler.update(GetFrameTime());
        }
    }
}