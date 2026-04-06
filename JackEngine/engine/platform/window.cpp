#include "window.h"
#include "../core/logger.h"
#include "../core/core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Jack
{
    Window::Window(unsigned int width, unsigned int height, const char* title)
    {
        if (!glfwInit())
        {
            JACK_LOG_ERROR("Failed to initialize GLFW");
            JACK_ASSERT(false, "GLFW initialization failed");
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Window = glfwCreateWindow(
            static_cast<int>(width),
            static_cast<int>(height),
            title,
            nullptr,
            nullptr
        );

        if (!m_Window)
        {
            JACK_LOG_ERROR("Failed to create GLFW window");
            glfwTerminate();
            JACK_ASSERT(false, "Window creation failed");
            return;
        }

        glfwMakeContextCurrent(m_Window);

        if (!gladLoadGL())
        {
            JACK_LOG_ERROR("Failed to initialize GLAD");
            glfwDestroyWindow(m_Window);
            m_Window = nullptr;
            glfwTerminate();
            JACK_ASSERT(false, "GLAD initialization failed");
            return;
        }

        JACK_LOG_INFO("OpenGL context created successfully");
        JACK_LOG_INFO(reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
        JACK_LOG_INFO(reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
        JACK_LOG_INFO(reinterpret_cast<const char*>(glGetString(GL_VERSION)));
    }

    Window::~Window()
    {
        if (m_Window)
        {
            glfwDestroyWindow(m_Window);
        }

        glfwTerminate();
        JACK_LOG_INFO("Window destroyed");
    }

    void Window::PollEvents() const
    {
        glfwPollEvents();
    }

    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(m_Window);
    }

    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }
}