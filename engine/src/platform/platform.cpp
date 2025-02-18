#include "platform.hpp"

Platform* Platform::instancePtr = nullptr;

Platform* Platform::getInstance() {
    if (instancePtr == nullptr) {
        if (instancePtr == nullptr) {
            instancePtr = new Platform();
        }
    }
    return instancePtr;
}
