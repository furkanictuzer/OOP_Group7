#ifndef MOCKCLOCK_H
#define MOCKCLOCK_H

#include <chrono>
#include <ctime>

static class MockClock
{
private:
    static std::chrono::system_clock::time_point current_time; // Static time point to store current time
    static int speed_factor;                                   // Static factor to control the time speed

public:
    static void initialize(int speed = 1);
    static std::chrono::system_clock::time_point getCurrentTime();
    static void advanceTime(std::chrono::seconds seconds);
    static void printCurrentTime();
};

#endif //! MOCKCLOCK_H