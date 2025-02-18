#pragma once

class ApplicationInterface {
    public:
        ApplicationInterface();
        virtual void init() = 0;
        virtual void deinit() = 0;
};
