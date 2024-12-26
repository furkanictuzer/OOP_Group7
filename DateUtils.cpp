#include "DateUtils.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <iostream>
#include <stdexcept>

/**
 * @brief Converts a date string to a std::chrono::system_clock::time_point.
 * 
 * The input string must follow the format "YYYY-MM-DD". If the conversion fails,
 * an exception is thrown.
 * 
 * @param timeStr The date string in "YYYY-MM-DD" format.
 * @return A std::chrono::system_clock::time_point representing the date.
 * @throws std::runtime_error if parsing or conversion fails.
 */
std::chrono::system_clock::time_point DateUtils::stringToTimePoint(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse time string");
    }
    std::time_t time = std::mktime(&tm);
    if (time == -1) {
        throw std::runtime_error("Failed to convert to time_t");
    }
    return std::chrono::system_clock::from_time_t(time);
}

/**
 * @brief Converts a std::chrono::system_clock::time_point to a string.
 * 
 * The output string follows the format "YYYY-MM-DD".
 * 
 * @param timePoint The time point to convert.
 * @return A string representation of the time point in "YYYY-MM-DD" format.
 */
std::string DateUtils::timePointToString(const std::chrono::system_clock::time_point& timePoint) {
    std::time_t time = std::chrono::system_clock::to_time_t(timePoint);
    std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}
