#ifndef REPEATEDEXPENSE_H
#define REPEATEDEXPENSE_H

#include "Expense.h"

class RepeatedExpense : public Expense {
private:
    std::string repeatInterval;
    int numberOfRepetition;

public:
    /**
     * @brief Constructs a new RepeatedExpense object.
     * 
     * @param id The unique identifier for the expense.
     * @param amount The amount of the expense.
     * @param date The date of the expense in string format.
     * @param description A brief description of the expense.
     * @param category A pointer to the Category object associated with the expense.
     * @param num The number of times the expense is repeated.
     */
    RepeatedExpense(int id, double amount, const std::string& date, const std::string& description, Category* category, int num);
    std::string calculateNextOccurrence() const;
};

#endif // REPEATEDEXPENSE_H
