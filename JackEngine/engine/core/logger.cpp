#include "logger.h"

#include <iostream>

void Jack::Logger::Info(const std::string& message)
{
	std::cout << "[INFO] - " << message << std::endl;
}

void Jack::Logger::Warning(const std::string& message)
{
	std::cout << "[WARNING] - " << message << std::endl;
}

void Jack::Logger::Error(const std::string& message)
{
	std::cout << "[ERROR] -" << message << std::endl;
}
