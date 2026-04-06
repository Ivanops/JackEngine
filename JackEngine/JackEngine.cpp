// JackEngine.cpp : Defines the entry point for the application.
//

#include "JackEngine.h"
#include "./engine/core/core.h"
#include "./engine/core/logger.h"

using namespace std;


int main()
{
    JACK_LOG_INFO("Engine initialized");
    JACK_LOG_WARN("Test warning");
    JACK_LOG_ERROR("Test error");

    while (true)
    {

    }

    return 0;
}