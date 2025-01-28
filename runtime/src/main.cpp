#include <core/uuid.hpp>
#include <debug/logger.hpp>

int main() {
    INFO(create_uuid64(), " Hello", 0.23);
    create_logger("engine.log");
    INFO(create_uuid64(), " Hello", 0.23);
    close_logger();
}
