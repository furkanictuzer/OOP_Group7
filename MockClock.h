#ifndef MOCK_CLOCK_H
#define MOCK_CLOCK_H

#include <chrono>

/**
 * @class MockClock
 * @brief Provides a mocked clock that allows controlling time for testing purposes.
 * 
 * This class simulates the passage of time, allowing you to initialize the time, advance it, 
 * and retrieve the current time based on a speed factor.
 */
class MockClock {
public:
    /**
     * @brief Initializes the mock clock with a specific speed.
     * 
     * The speed factor controls how fast time advances when using `advanceTime`.
     * 
     * @param speed A factor by which time advances. Default value is 1.
     */
    static void initialize(int speed = 1);

    /**
     * @brief Advances the current time by a specified duration.
     * 
     * This function increases the mock clock's time by the given duration, adjusted for the clock's speed.
     * 
     * @param duration The amount of time to advance, represented in seconds.
     */
    static void advanceTime(std::chrono::seconds duration);

    /**
     * @brief Retrieves the current time of the mock clock.
     * 
     * This function returns the current time of the mock clock as a `std::chrono::system_clock::time_point`.
     * 
     * @return The current time as a `std::chrono::system_clock::time_point`.
     */
    static std::chrono::system_clock::time_point getCurrentTime();

private:
    static std::chrono::system_clock::time_point _time; ///< The current time of the mock clock.
    static int _speed; ///< The speed factor controlling the rate of time advancement.
};

#endif // MOCK_CLOCK_H
