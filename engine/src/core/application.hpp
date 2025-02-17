#pragma once

class ApplicationInterface {
    public:
        virtual void init() = 0;
        virtual void deinit() = 0;
};
