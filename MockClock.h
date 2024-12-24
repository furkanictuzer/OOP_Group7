#ifndef MOCK_CLOCK_H
#define MOCK_CLOCK_H

#include <chrono>

class MockClock {
public:
    static void initialize(int speed = 1);
    static void advanceTime(std::chrono::seconds duration);
    static std::chrono::system_clock::time_point getCurrentTime();

private:
    static std::chrono::system_clock::time_point _time;
    static int _speed;
};

#endif // MOCK_CLOCK_H