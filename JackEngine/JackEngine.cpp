// JackEngine.cpp : Defines the entry point for the application.
//

#include "JackEngine.h"
#include <iostream>
#include "./engine/core/logger.h"

using namespace std;


int main()
{
    Jack::Logger::Info("jack Engine Starting");
    Jack::Logger::Warning("jack Engine test warning");
    Jack::Logger::Error("jack Engine Test Error");

    while (true)
    {

    }

    return 0;
}