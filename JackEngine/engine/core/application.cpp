#include "application.h"
#include "logger.h"
#include "core.h"
#include "timer.h"
#include "../platform/window.h"

#include <thread>
#include <string>
#include <glad/glad.h>

namespace Jack
{
    Application::Application()
    {
        JACK_LOG_INFO("Application created");
        m_Window = new Window(1280, 720, "Jack Engine");
    }

    Application::~Application()
    {
        delete m_Window;
        m_Window = nullptr;

        JACK_LOG_INFO("Application destroyed");
    }

    void Application::Run()
    {
        JACK_LOG_INFO("Application running");

        Timer timer;
        double lastTime = timer.ElapsedSeconds();
        double logAccumulator = 0.0;

        while (m_Running)
        {
            double currentTime = timer.ElapsedSeconds();
            double deltaTime = currentTime - lastTime;
            lastTime = currentTime;

            logAccumulator += deltaTime;
            if (logAccumulator >= 1.0)
            {
                JACK_LOG_INFO("Delta Time: " + std::to_string(deltaTime));
                logAccumulator = 0.0;
            }

            glViewport(0, 0, 1280, 720);
            glClearColor(0.1f, 0.1f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_Window->SwapBuffers();
            m_Window->PollEvents();

            if (m_Window->ShouldClose())
            {
                m_Running = false;
            }
        }
    }
}