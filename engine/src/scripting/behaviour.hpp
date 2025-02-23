#pragma once

#include <scene/components.hpp>

class Entity;

class Behaviour: Component {
    public:
        Behaviour();
        ~Behaviour();

    public:
        virtual void start() = 0;
        virtual void update(float delta) = 0;
        virtual void late_update(float delta) = 0;
        virtual void exit() = 0;
    private:
        Entity* entity;
};
