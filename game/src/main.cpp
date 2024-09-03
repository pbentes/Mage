#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#include <Core/Application.h>

int main() {
    Engine::Application app("Game application");
    app.run();
}