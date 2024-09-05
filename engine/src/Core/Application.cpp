#include "Application.h"
#include "../Debug/Instrumentor.h"

#include <raylib.h>

namespace Engine {
    Application::Application(const char* window_title) {
        Instrumentor::Get().BeginSession("Engine");

        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, window_title);

        this->m_RenderTexture = LoadRenderTexture(GetRenderWidth(), GetRenderHeight());
    }

    Application::~Application() {
        CloseWindow();
        Instrumentor::Get().EndSession();
    }

    void Application::run() {
        PROFILE_SCOPE("Run Function");

        while (!WindowShouldClose())
        {
            PROFILE_SCOPE("Main Loop");
            BeginTextureMode(this->m_RenderTexture);
                ClearBackground(Color {90 , 99 , 156, 255});
            EndTextureMode();

            BeginDrawing();
                ClearBackground(MAGENTA);
                DrawTextureRec(this->m_RenderTexture.texture, Rectangle{ 0, 0, (float)this->m_RenderTexture.texture.width, (float)-this->m_RenderTexture.texture.height }, Vector2{ 0, 0 }, WHITE);
                // Post Processing
                // GUI
                DrawFPS(10, 10);
            EndDrawing();
        }
    }
}