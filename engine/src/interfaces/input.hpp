#pragma once

typedef struct Action {
    const char* name;
    int* key_bindings;
    int binding_count;
    bool is_pressed;
    bool was_pressed;
    bool just_pressed;
    bool just_released;
} Action;

typedef struct Input Input;

typedef struct InputAPI {
    void (*update)(Input*);
} InputAPI;

typedef struct Input {
    void (*initialize)(void);
    void (*shutdown)(void);
    void (*register_action)(const char* action_name, int default_key);
    void (*unregister_action)(const char* action_name);
    bool (*is_action_pressed)(const char* action_name);
    bool (*is_action_released)(const char* action_name);
    bool (*is_action_just_pressed)(const char* action_name);
    bool (*is_action_just_released)(const char* action_name);
    void (*rebind_action)(const char* action_name, int new_key);

    InputAPI* input_api;
} Input;
