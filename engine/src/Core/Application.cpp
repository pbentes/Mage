#include "Application.h"

#include <raylib.h>

namespace Engine {
    Application::Application(const char* window_title) {
        const int screenWidth = 800;
        const int screenHeight = 450;

        InitWindow(screenWidth, screenHeight, window_title);
    }

    Application::~Application() {
        CloseWindow();
    }

    void Application::run() {
        while (!WindowShouldClose())
        {
            BeginDrawing();
                ClearBackground(Color {90 , 99 , 156, 255});
                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            EndDrawing();
        }
    }
}