#include <core/uuid.hpp>
#include <cstdint>
#include <debug/logger.hpp>

int main() {
    Uuid64 uuid;

    INFO(uuid, " Hello", 0.23);
    create_logger("engine.log");
    INFO(*(new Uuid64()), " Hello", 0.23);
    close_logger();
}
