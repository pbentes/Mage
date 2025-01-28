#pragma once

#include <cstdint>

typedef struct uuid64 {
    uint64_t uuid;

    operator uint64_t () { return uuid; }
    operator const uint64_t () const { return uuid; }
} uuid64;

uuid64 create_uuid64();

typedef struct uuid32 {
    uint32_t uuid;

    operator uint32_t () { return uuid; }
    operator const uint32_t () const { return uuid; }
} uuid32;

uuid32 create_uuid32();