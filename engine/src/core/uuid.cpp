#include "uuid.hpp"

#include <random>

static std::random_device random_device;

static std::mt19937_64 eng64(random_device());
static std::uniform_int_distribution<uint64_t> uniform_distribution64;

static std::mt19937 eng32(random_device());
static std::uniform_int_distribution<uint32_t> uniform_distribution32;

Uuid64::Uuid64() {
    uuid = uniform_distribution64(eng64);
}

Uuid32::Uuid32() {
    uuid = uniform_distribution32(eng32);
}
