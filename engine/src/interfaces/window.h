#pragma once

#include "../core/window.h"

typedef struct WindowAPI {
    Window (*create)(void);
    void (*close)(Window*);
} WindowAPI;