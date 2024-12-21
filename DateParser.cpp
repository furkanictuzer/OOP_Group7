#include <iostream>
#include <string>
#include "DateParser.h"

// Statik fonksiyon
void DateParser::parseDate(const std::string& date, int& day, int& month, int& year) {
    size_t firstDot = date.find('.');
    size_t secondDot = date.find('.', firstDot + 1);

    // Parçalama iþlemi
    day = std::stoi(date.substr(0, firstDot));
    month = std::stoi(date.substr(firstDot + 1, secondDot - firstDot - 1));
    year = std::stoi(date.substr(secondDot + 1));
}

std::string DateParser::addDate(const std::string& date1, const std::string& date2)
{
    /**
    *Parsing dates
    */
    int date1Day, date1Month, date1Year;
    parseDate(date1, date1Day, date1Month, date1Year);

    int date2Day, date2Month, date2Year;
    parseDate(date2, date2Day, date2Month, date2Year);

    /**
    *Assigninging values to the newDate
    */
    std::string newDate;
    int newDateDay, newDateMonth, newDateYear;

    newDateYear = date2Year + date1Year;
    newDateMonth = date2Month + date1Month;
    newDateDay = date2Day + date1Day;

    /**
    *Rearranging the month and day values to be normal
    */
    switch (newDateMonth % 12)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        while (newDateDay >= 31)
        {
            newDateDay -= 31;
            newDateMonth++;
        }
        break;
    case 2:
    case 4:
    case 6:
    case 9:
    case 11:
        while (newDateDay >= 30)
        {
            newDateDay -= 30;
            newDateMonth++;
        }
        break;
    default:
        break;
    }

    while (newDateMonth > 12)
    {
        newDateMonth -= 12;
        newDateYear++;
    }

    /**
    *Constructing and returning the newDate
    */

    std::string newDateDayStr = newDateDay > 9 ? std::to_string(newDateDay) : "0" + std::to_string(newDateDay);
    std::string newDateMonthStr = newDateMonth > 9 ? std::to_string(newDateMonth) : "0" + std::to_string(newDateMonth);

    newDate = newDateDayStr + "." + newDateMonthStr + "." + std::to_string(newDateYear);

    return newDate;

}
