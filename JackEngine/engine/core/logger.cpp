#include "logger.h"

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

namespace Jack
{
	void SetColor(int color)
	{
		#ifdef _WIN32
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		#endif
	}

	void ResetColor()
	{
		#ifdef _WIN32
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		#endif
	}
}


void Jack::Logger::Info(const std::string& message)
{
	SetColor(10); // green
	std::cout << "[INFO] - " << message << std::endl;
	ResetColor();
}

void Jack::Logger::Warning(const std::string& message)
{
	SetColor(14); // yellow
	std::cout << "[WARNING] - " << message << std::endl;
	ResetColor();
}

void Jack::Logger::Error(const std::string& message)
{
	SetColor(12); // red
	std::cout << "[ERROR] -" << message << std::endl;
	ResetColor();
}
