#pragma once

typedef struct RendererAPI {
    void (*init)(void);
    void (*cleanup)(void);

    void (*begin_frame)(void);
    void (*end_frame)(void);
} RendererAPI;
