#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <string>
#include <chrono>

class DateUtils {
public:
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
    static std::string timePointToString(const std::chrono::system_clock::time_point& timePoint);
};

#endif // DATEUTILS_H