#pragma once

struct GLFWwindow;

namespace Jack
{
    class Window
    {
    public:
        Window(unsigned int width, unsigned int height, const char* title);
        ~Window();

        void PollEvents() const;
        void SwapBuffers() const;
        bool ShouldClose() const;

    private:
        GLFWwindow* m_Window = nullptr;
    };
}