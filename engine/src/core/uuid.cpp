#include "uuid.hpp"

#include <random>

static std::random_device random_device;

static std::mt19937_64 eng64(random_device());
static std::uniform_int_distribution<uint64_t> uniform_distribution64;

static std::mt19937 eng32(random_device());
static std::uniform_int_distribution<uint32_t> uniform_distribution32;

uuid64 create_uuid64() {
    return uuid64 {
        .uuid = uniform_distribution64(eng64)
    };
}

uuid32 create_uuid32() {
    return uuid32 {
        .uuid = uniform_distribution32(eng32)
    };
}
