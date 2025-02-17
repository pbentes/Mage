#pragma once

#include <cstdint>

class Uuid64 {
    public:
        Uuid64();

    private:
        uint64_t uuid;

    public:
        operator uint64_t () { return uuid; }
        operator const uint64_t () const { return uuid; }
};

class Uuid32 {
    public:
        Uuid32();

    private:
        uint32_t uuid;

    public:
        operator uint32_t () { return uuid; }
        operator const uint32_t () const { return uuid; }
};
