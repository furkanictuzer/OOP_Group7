#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <string>
#include <chrono>

/**
 * @class DateUtils
 * @brief Provides utility functions for converting between time strings and time points.
 */
class DateUtils {
public:
    /**
     * @brief Converts a string representation of a time to a time_point.
     * 
     * This function parses a time string (in a specific format) and converts it to a `std::chrono::system_clock::time_point` object.
     * 
     * @param timeStr A string representing the time to be converted.
     * @return A `std::chrono::system_clock::time_point` object representing the parsed time.
     */
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);

    /**
     * @brief Converts a time_point to a string representation.
     * 
     * This function converts a `std::chrono::system_clock::time_point` to a string in a readable format.
     * 
     * @param timePoint The `std::chrono::system_clock::time_point` to be converted.
     * @return A string representation of the given time point.
     */
    static std::string timePointToString(const std::chrono::system_clock::time_point& timePoint);
};

#endif // DATEUTILS_H
