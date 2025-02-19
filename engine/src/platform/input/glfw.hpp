#pragma once

#include "input/input.hpp"

class GlfwInputApi: InputInterface {
    public:
        void update(Action* action) override;
};
