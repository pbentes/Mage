#pragma once

typedef struct RendererAPI {
    void (*Initialize)(void);
    void (*Shutdown)(void);

    void (*BeginFrame)(void);
    void (*EndFrame)(void);
} RendererAPI;