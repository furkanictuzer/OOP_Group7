#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <chrono>
#include "Category.h"

// Forward declaration
class Category;

/**
 * @class Expense
 * @brief Represents an expense with details such as amount, date, description, and category.
 */
class Expense
{
private:
    int id;                                     ///< The unique identifier of the expense.
    double amount;                              ///< The amount of the expense.
    std::chrono::system_clock::time_point date; ///< The date and time when the expense was made, represented as a time_point.
    Category *category;                         ///< The category to which the expense belongs.
    std::string description;                    ///< A description of the expense.

public:
    Expense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category);
    virtual ~Expense();

    void setExpenseDetails(double amount, const std::string& description);
    std::string getExpenseDetails() const;

    /**
     * @brief Gets the amount of the expense.
     * @return The amount of the expense.
     */
    double getAmount() const;

    /**
     * @brief Gets the unique identifier of the expense.
     * @return The ID of the expense.
     */
    int getId() const;

    /**
     * @brief Gets the date when the expense was made.
     * @return The date of the expense as a time_point.
     */
    std::chrono::system_clock::time_point getDate() const;

    /**
     * @brief Gets the category to which the expense belongs.
     * @return A pointer to the Category associated with the expense.
     */
    Category *getCategory() const;

    /**
     * @brief Gets the description of the expense.
     * @return The description of the expense.
     */
    std::string getDescription() const;

    /**
     * @brief Compares two expenses for equality based on their ID.
     *
     * @param other The other expense to compare with.
     * @return true if the expenses are equal, false otherwise.
     */
    bool operator==(const Expense &other) const;
};

#endif // EXPENSE_H
