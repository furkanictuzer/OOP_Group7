#include "RepeatedExpense.h"
#include <sstream>
#include <iomanip>

RepeatedExpense::RepeatedExpense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category, int num, const std::chrono::hours& interval)
    : Expense(id, amount, date, description, category), numberOfRepetition(num), repeatInterval(interval) {}

std::chrono::system_clock::time_point RepeatedExpense::calculateNextOccurrence() const {
    return getDate() + repeatInterval;
}
