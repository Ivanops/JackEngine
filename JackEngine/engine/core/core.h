#pragma once

// Platform detection (simple)
#ifdef _WIN32
	#define JACK_PLATFORM_WINDOWS
#endif

// Logging macros
#define JACK_LOG_INFO(x)    ::Jack::Logger::Info(x)
#define JACK_LOG_WARN(x)    ::Jack::Logger::Warning(x)
#define JACK_LOG_ERROR(x)   ::Jack::Logger::Error(x)