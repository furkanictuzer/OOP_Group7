#include <iostream>
#include <chrono>
#include <ctime>

class MockClock {
private:
    static std::chrono::system_clock::time_point current_time; // Static time point to store current time
    static int speed_factor; // Static factor to control the time speed

public:
    // Set the initial time and define the speed factor
    static void initialize(int speed = 1) {
        current_time = std::chrono::system_clock::now(); // Get current time
        speed_factor = speed; // Set the speed factor
    }

    // Get the current time (chrono type)
    static std::chrono::system_clock::time_point getCurrentTime() {
        return current_time;
    }

    // Advance time by the given seconds, considering the speed factor
    static void advanceTime(std::chrono::seconds seconds) {
        current_time += seconds * speed_factor; // Increase the time considering speed factor
    }

    // Print the current time in a human-readable format (day, month, year, hour, minute, second)
    static void printCurrentTime() {
        std::time_t now = std::chrono::system_clock::to_time_t(current_time); // Convert time_point to time_t
        std::tm *local_time = std::localtime(&now); // Convert time_t to local time (tm structure)

        // Print the current time in the format: Year-Month-Day Hour:Minute:Second
        std::cout << "Time: "
                  << local_time->tm_year + 1900 << "-"  // Year
                  << local_time->tm_mon + 1 << "-"     // Month
                  << local_time->tm_mday << " "        // Day
                  << local_time->tm_hour << ":"       // Hour
                  << local_time->tm_min << ":"        // Minute
                  << local_time->tm_sec << std::endl; // Second
    }
};

// Initialize static members
std::chrono::system_clock::time_point MockClock::current_time;
int MockClock::speed_factor;