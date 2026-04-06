#pragma once
#include <string>

#ifdef _WIN32
#define JACK_PLATFORM_WINDOWS
#endif

#ifdef _MSC_VER
#define JACK_DEBUGBREAK() __debugbreak()
#else
#include <csignal>
#define JACK_DEBUGBREAK() raise(SIGTRAP)
#endif

#ifdef _DEBUG
#define JACK_ENABLE_ASSERTS
#endif

#define JACK_LOG_INFO(x)  ::Jack::Logger::Info(x)
#define JACK_LOG_WARN(x)  ::Jack::Logger::Warning(x)
#define JACK_LOG_ERROR(x) ::Jack::Logger::Error(x)

#ifdef JACK_ENABLE_ASSERTS
#define JACK_ASSERT(condition, message)                                                \
        do                                                                                  \
        {                                                                                   \
            if (!(condition))                                                               \
            {                                                                               \
                ::Jack::Logger::Error(std::string("Assertion failed: ") + #condition);     \
                ::Jack::Logger::Error(std::string("Message: ") + message);                 \
                ::Jack::Logger::Error(std::string("File: ") + __FILE__);                   \
                ::Jack::Logger::Error(std::string("Line: ") + std::to_string(__LINE__));   \
                JACK_DEBUGBREAK();                                                          \
            }                                                                               \
        } while (false)
#else
#define JACK_ASSERT(condition, message) do { } while (false)
#endif