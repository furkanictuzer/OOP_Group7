#ifndef REPEATEDEXPENSE_H
#define REPEATEDEXPENSE_H

#include "Expense.h"
#include <chrono>

class RepeatedExpense : public Expense {
private:
    int numberOfRepetition;
    std::chrono::hours repeatInterval;

public:
    RepeatedExpense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category, int num, const std::chrono::hours& interval);
    std::chrono::system_clock::time_point calculateNextOccurrence() const;
};

#endif // REPEATEDEXPENSE_H
