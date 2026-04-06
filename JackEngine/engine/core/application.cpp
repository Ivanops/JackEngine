#include "application.h"
#include "logger.h"
#include "core.h"
#include "timer.h"

#include <thread>
#include <string>

namespace Jack
{
    Application::Application()
    {
        JACK_LOG_INFO("Application created");
    }

    Application::~Application()
    {
        JACK_LOG_INFO("Application destroyed");
    }

    void Application::Run()
    {
        JACK_LOG_INFO("Application running");

        Timer timer;
        double lastTime = timer.ElapsedSeconds();

        int frameCount = 0;

        while (m_Running)
        {
            double currentTime = timer.ElapsedSeconds();
            double deltaTime = currentTime - lastTime;
            lastTime = currentTime;

            JACK_LOG_INFO(
                "Frame: " + std::to_string(frameCount) +
                " | Delta Time: " + std::to_string(deltaTime)
            );
            std::this_thread::sleep_for(std::chrono::milliseconds(16));

            frameCount++;

            if (frameCount >= 5)
            {
                m_Running = false;
            }
        }
    }
}