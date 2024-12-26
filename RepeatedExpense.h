#ifndef REPEATEDEXPENSE_H
#define REPEATEDEXPENSE_H

#include "Expense.h"
#include <chrono>

/**
 * @class RepeatedExpense
 * @brief Represents an expense that repeats over a specified interval.
 * 
 * This class extends the `Expense` class and adds functionality to handle repeated expenses,
 * including calculating the next occurrence of the expense based on the specified interval.
 */
class RepeatedExpense : public Expense {
private:
    int numberOfRepetition; ///< The number of times the expense will repeat.
    std::chrono::hours repeatInterval; ///< The interval at which the expense repeats.

public:
    /**
     * @brief Constructs a RepeatedExpense object.
     * 
     * Initializes a repeated expense with the given details, including the number of repetitions
     * and the interval between repetitions.
     * 
     * @param id The ID of the expense.
     * @param amount The amount of the expense.
     * @param date The date of the expense.
     * @param description A description of the expense.
     * @param category The category associated with the expense.
     * @param num The number of times the expense should repeat.
     * @param interval The interval between each repetition of the expense.
     */
    RepeatedExpense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category, int num, const std::chrono::hours& interval);

    /**
     * @brief Calculates the next occurrence of the repeated expense.
     * 
     * This function calculates when the next occurrence of the repeated expense will be, 
     * based on the current date and the repeat interval.
     * 
     * @return The `std::chrono::system_clock::time_point` representing the next occurrence of the expense.
     */
    std::chrono::system_clock::time_point calculateNextOccurrence() const;
    int getRepeatCount() const;
};

#endif // REPEATEDEXPENSE_H
