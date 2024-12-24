#include <iostream>
#include "MockClock.h"

std::chrono::system_clock::time_point MockClock::_time;
int MockClock::_speed = 1;

// Set the initial time and define the speed factor
void MockClock::initialize(int speed)
{
    _speed = speed;
    _time = std::chrono::system_clock::now();
}

// Get the current time (chrono type)
std::chrono::system_clock::time_point MockClock::getCurrentTime()
{
    return _time;
}

// Advance time by the given seconds, considering the speed factor
void MockClock::advanceTime(std::chrono::seconds duration)
{
    _time += duration * _speed;
}