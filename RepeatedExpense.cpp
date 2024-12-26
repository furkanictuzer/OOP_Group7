#include "RepeatedExpense.h"
#include <sstream>
#include <iomanip>

/**
 * @brief Constructor for RepeatedExpense class.
 * 
 * This constructor initializes a repeated expense with the specified parameters.
 * It extends from the `Expense` class and adds the functionality of repetition and interval.
 * 
 * @param id The unique identifier for the expense.
 * @param amount The amount of the expense.
 * @param date The date of the expense occurrence.
 * @param description A description of the expense.
 * @param category The category associated with the expense.
 * @param num The number of repetitions for this expense.
 * @param interval The time interval between each occurrence of the expense.
 */
RepeatedExpense::RepeatedExpense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category, int num, const std::chrono::hours& interval)
    : Expense(id, amount, date, description, category), numberOfRepetition(num), repeatInterval(interval) {}

/**
 * @brief Calculates the next occurrence of the repeated expense.
 * 
 * This function calculates the next occurrence of the repeated expense based on the given time interval.
 * The next occurrence is calculated by adding the `repeatInterval` to the original expense date.
 * 
 * @return The `time_point` representing the next occurrence of the expense.
 */
std::chrono::system_clock::time_point RepeatedExpense::calculateNextOccurrence() const {
    return getDate() + repeatInterval;
}

/**
 * @brief Retrieves the number of times the expense is repeated.
 * 
 * This function returns the number of repetitions for the repeated expense, i.e., how many times 
 * the expense should be repeated.
 * 
 * @return The number of repetitions for this expense.
 */
int RepeatedExpense::getRepeatCount() const {
    return numberOfRepetition;
}
