#pragma once

namespace Jack
{
    class Window;

    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        bool m_Running = true;
        Window* m_Window = nullptr;
    };
}