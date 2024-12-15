#ifndef REPEATEDEXPENSE_H
#define REPEATEDEXPENSE_H

#include "Expense.h"

class RepeatedExpense : public Expense {
private:
    std::string repeatInterval;
    int numberOfRepetition;

public:
    RepeatedExpense(int id, double amount, const std::string& date, const std::string& description, const Category& category, int num);
    std::string calculateNextOccurrence() const;
};

#endif // REPEATEDEXPENSE_H
