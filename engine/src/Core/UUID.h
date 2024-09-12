#pragma once

#include <cstdint>

namespace Engine {
    class UUID64 {
        public:
            UUID64();
            UUID64(uint64_t uuid);
            UUID64(const UUID64& other);

            operator uint64_t () { return m_UUID; }
            operator const uint64_t () const { return m_UUID; }
        public:
            uint64_t m_UUID;
    };

    class UUID32 {
        public:
            UUID32();
            UUID32(uint32_t uuid);
            UUID32(const UUID32& other);

            operator uint32_t () { return m_UUID; }
            operator const uint32_t () const { return m_UUID; }
        public:
            uint32_t m_UUID;
    };
}