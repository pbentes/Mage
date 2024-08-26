#pragma once

#ifndef DllExport
#define DllExport __declspec( dllexport )
#endif

#include <flecs.h>
#include <flecs/addons/cpp/world.hpp>

namespace engine {
    void RegisterRaylibComponents(flecs::world* world);
}