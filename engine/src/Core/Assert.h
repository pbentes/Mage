#pragma once

#include "../Debug/Logger.h"

#ifndef NDEBUG
    #define ENABLE_ASSERTS
#endif

#ifdef ENABLE_ASSERTS
    #define ENGINE_ASSERT(condition, ...) ::Engine::Logger::GetInstance().Assert(condition, "ENGINE_ASSERTION_FAILED", ##__VA_ARGS__)
    #define ASSERT(condition, ...) ::Engine::Logger::GetInstance().Assert(condition, "ASSERTION_FAILED", ##__VA_ARGS__)
#else
    #define ENGINE_ASSERT(condition, ...) ((void)0)
    #define ASSERT(condition, ...) ((void)0)
#endif