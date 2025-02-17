#pragma once

#include "../../core/application.hpp"

class GlfwApplicationApi: ApplicationInterface {
    public:
        void init() override;
        void deinit() override;
};
