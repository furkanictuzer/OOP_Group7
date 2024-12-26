#include <iostream>
#include "MockClock.h"

std::chrono::system_clock::time_point MockClock::_time;
int MockClock::_speed = 1;

/**
 * @brief Initializes the mock clock with a given speed factor.
 * 
 * This function sets the initial time to the current system time and defines the speed at which the time will advance.
 * The speed factor is used to determine how much faster time should advance when the `advanceTime` function is called.
 *
 * @param speed The factor by which time should be accelerated. Default is 1 (real-time).
 */
void MockClock::initialize(int speed)
{
    _speed = speed;
    _time = std::chrono::system_clock::now();
}

/**
 * @brief Gets the current time according to the mock clock.
 * 
 * This function returns the current time as a `std::chrono::system_clock::time_point`. 
 * The time is simulated and can be advanced using the `advanceTime` function.
 *
 * @return The current time represented as a `std::chrono::system_clock::time_point`.
 */
std::chrono::system_clock::time_point MockClock::getCurrentTime()
{
    return _time;
}

/**
 * @brief Advances the time by a specified duration, factoring in the speed.
 * 
 * This function increments the time by the specified duration, multiplying it by the speed factor to simulate the passage of time.
 * For example, a speed of 2 would advance time twice as fast.
 * 
 * @param duration The amount of time to advance, specified as `std::chrono::seconds`.
 */
void MockClock::advanceTime(std::chrono::seconds duration)
{
    _time += duration * _speed;
}
