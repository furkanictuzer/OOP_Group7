#include <iostream>
#include <string>
#include "DateParser.h"

class DateParser {
public:
    // Statik fonksiyon
    static void parseDate(const std::string& date, int& day, int& month, int& year) {
        size_t firstDot = date.find('.');
        size_t secondDot = date.find('.', firstDot + 1);

        // Parçalama işlemi
        day = std::stoi(date.substr(0, firstDot));
        month = std::stoi(date.substr(firstDot + 1, secondDot - firstDot - 1));
        year = std::stoi(date.substr(secondDot + 1));
    }
};