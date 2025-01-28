#pragma once

#include <cstddef>

typedef enum FieldType {
    Integer,
    Float,
    Boolean,
    String,
    Pointer,
    Custom,
    Unknown
} FieldType;

typedef struct Reflection {
    char* name;
    FieldType type;
    char* type_name;
    Reflection& custom_type_reflection;
    void* value;
    size_t offset;
    Reflection* next = nullptr;
} Reflection;
