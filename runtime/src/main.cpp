#include <Assets/AssetDatabase.h>
#include <Core/Application.h>

#include <filesystem>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::string project_path;

    if (argc < 1)
        project_path = std::filesystem::current_path().remove_filename().string() + "/project";
    else
        project_path = std::string(argv[1]);

    std::cout << project_path << std::endl;

    Engine::AssetDatabase asset_db(std::vector<std::string> { project_path });
    Engine::Application app;
    app.run();
}