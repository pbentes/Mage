#include "Renderer.h"
#include "raylib.h"

namespace Engine {
    Renderer::Renderer() {}
    Renderer::~Renderer() {}

    void Renderer::init() {
        const int screenWidth = 800;
        const int screenHeight = 450;

        SetConfigFlags(FLAG_WINDOW_RESIZABLE|FLAG_WINDOW_MAXIMIZED);
        InitWindow(screenWidth, screenHeight, "");
        MaximizeWindow();

        this->m_RenderTexture = LoadRenderTexture(GetRenderWidth(), GetRenderHeight());
    }

    void Renderer::update(Renderer::delta_type delta, void*) {
        if (IsWindowResized()) {
            UnloadRenderTexture(this->m_RenderTexture);
            this->m_RenderTexture = LoadRenderTexture(GetRenderWidth(), GetRenderHeight());
        }

        BeginTextureMode(this->m_RenderTexture);
            ClearBackground(Color {90 , 99 , 156, 255});
            DrawFPS(10, 10);
        EndTextureMode();

        BeginDrawing();
            ClearBackground(MAGENTA);
            DrawTextureRec(this->m_RenderTexture.texture, Rectangle{ 0, 0, (float)this->m_RenderTexture.texture.width, (float)-this->m_RenderTexture.texture.height }, Vector2{ 0, 0 }, WHITE);
            
            // Post Processing
            
            // GUI
            
        EndDrawing();

        if (WindowShouldClose())
            succeed();
    }

    void Renderer::succeeded() { CloseWindow(); }
    void Renderer::failed() { CloseWindow(); }
    void Renderer::aborted() { CloseWindow(); }
}