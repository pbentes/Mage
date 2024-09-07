#include "Application.h"

#include "../Debug/Instrumentor.h"
#include "../Renderer/Renderer.h"
#include "../Scripting/Scripting.h"

#include <raylib.h>

namespace Engine {
    Application::Application() {
        Instrumentor::Get().BeginSession("Engine");
        m_Scheduler.attach<Scripting>()
            .attach<Renderer>();
    }

    Application::~Application() {
        Instrumentor::Get().EndSession();
    }

    void Application::run() {
        PROFILE_SCOPE("Run Function");
        while (!m_Scheduler.empty())
        {
            m_Scheduler.update(GetFrameTime());

            if (WindowShouldClose())
                m_Scheduler.abort();
        }
    }
}