#include "Timer.h"

namespace Jack
{
    Timer::Timer()
    {
        Reset();
    }

    void Timer::Reset()
    {
        m_StartTime = std::chrono::high_resolution_clock::now();
    }

    double Timer::ElapsedSeconds() const
    {
        return std::chrono::duration<double>(
            std::chrono::high_resolution_clock::now() - m_StartTime
        ).count();
    }

    double Timer::ElapsedMilliseconds() const
    {
        return std::chrono::duration<double, std::milli>(
            std::chrono::high_resolution_clock::now() - m_StartTime
        ).count();
    }
}