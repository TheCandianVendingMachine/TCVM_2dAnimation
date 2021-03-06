// time.hpp
// A class to store time values
#pragma once
#define FLAT_ENGINE_API
#include <cstdint>

namespace fe 
    {
        class time
            {
                private:
                    // time as microseconds
                    long long m_time;

                    friend FLAT_ENGINE_API fe::time seconds(const long double in);
                    friend FLAT_ENGINE_API fe::time milliseconds(const long double in);
                    friend FLAT_ENGINE_API fe::time microseconds(const long double in);

                public:
                    FLAT_ENGINE_API time();

                    FLAT_ENGINE_API float asSeconds();
                    FLAT_ENGINE_API int32_t asMilliseconds();
                    FLAT_ENGINE_API int64_t asMicroseconds();

                    FLAT_ENGINE_API fe::time operator+(const fe::time &rhs);
                    FLAT_ENGINE_API fe::time operator-(const fe::time & rhs);
                    FLAT_ENGINE_API void operator+=(const fe::time &rhs);
                    FLAT_ENGINE_API void operator-=(const fe::time &rhs);

                    FLAT_ENGINE_API fe::time &operator=(const fe::time &rhs);

                    FLAT_ENGINE_API bool operator==(const fe::time &rhs);

            };

        FLAT_ENGINE_API fe::time seconds(const long double in);
        FLAT_ENGINE_API fe::time milliseconds(const long double in);
        FLAT_ENGINE_API fe::time microseconds(const long double in);
        FLAT_ENGINE_API fe::time zero();
    }