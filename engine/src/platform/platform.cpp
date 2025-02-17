#include "platform.hpp"

Platform* Platform::getInstance() {
    if (instancePtr == nullptr) {
        std::lock_guard<std::mutex> lock(mtx);
        if (instancePtr == nullptr) {
            instancePtr = new Platform();
        }
    }
    return instancePtr;
}
