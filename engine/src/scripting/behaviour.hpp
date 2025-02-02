#pragma once

#include "../core/reflection.hpp"

typedef struct Behaviour {
    const char* stringname = nullptr;

    void* data = nullptr;
    Reflection* (*reflect_data)(void*) = nullptr;

    void (*init)(void) = nullptr;
    void (*update)(float) = nullptr;
    void (*late_update)(float) = nullptr;
    void (*on_render)(void) = nullptr;
    void (*exit)(void) = nullptr;
} Behaviour;
