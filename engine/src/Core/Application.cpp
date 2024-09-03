#include "Application.h"
#include "../Debug/Instrumentor.h"

#include <raylib.h>

namespace Engine {
    Application::Application(const char* window_title) {
        Instrumentor::Get().BeginSession("Engine");

        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, window_title);
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
            BeginDrawing();
                ClearBackground(Color {90 , 99 , 156, 255});
                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            EndDrawing();
        }
    }
}