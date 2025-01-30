#pragma once

#include "../core/reflection.hpp"

typedef struct Behaviour {
    const char* stringname;

    void* data;
    Reflection* (*reflect_data)(void*);

    void (*init)(void);
    void (*update)(float);
    void (*late_update)(float);
    void (*on_render)(void);
    void (*exit)(void);
} Behaviour;
