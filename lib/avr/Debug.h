#pragma once
#ifndef EMBEDDEDUTILS_DEBUG_H
#define EMBEDDEDUTILS_DEBUG_H

#include <stdarg.h>

#if defined(TEENSYDUINO) || defined(__AVR__) || defined(__MBED__)

namespace Debug
{
    void Assert(bool b, const char* file, int line, const char* func, const char* expr)
    {
        while (!b)
        {
            Serial.print("[ASSERT] ");
            Serial.print(file);
            Serial.print(":");
            Serial.print(line);
            Serial.print(":");
            Serial.print(func);
            Serial.print("() : ");
            Serial.println(expr);
        }
    }
}

#ifdef NDEBUG

#define ASSERT(b) ((void)0)
#define LOG_VERBOSE(s,...) ((void)0)
#define LOG_NOTICE(s,...) ((void)0)
#define LOG_WARNING(s,...) ((void)0)
#define LOG_ERROR(s,...) ((void)0)

#else // NDEBUG

#define ASSERT(b) Debug::Assert((b), __FILE__, __LINE__, __func__, #b)
#if 0
#define LOG_VERBOSE(s,...) Serial.printf("[Verbose] %s:%d:%s() : " s "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_NOTICE(s,...) Serial.printf("[Notice] %s:%d:%s() : " s "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_WARNING(s,...) Serial.printf("[Warning] %s:%d:%s() : " s "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define LOG_ERROR(s,...) Serial.printf("[Error] %s:%d:%s() : " s "\n", __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#endif

#endif // #ifdef NDEBUG
#endif // #if defined(TEENSYDUINO) || defined(__AVR__) || defined(__MBED__)

#endif // EMBEDDEDUTILS_DEBUG_H
