#pragma once

typedef struct RendererAPI {
    void (*init)(void) = nullptr;
    void (*cleanup)(void) = nullptr;

    void (*begin_frame)(void) = nullptr;
    void (*end_frame)(void) = nullptr;
} RendererAPI;
