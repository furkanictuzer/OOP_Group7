#ifndef BUDGET_H
#define BUDGET_H

#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono> 
#include "DateUtils.h"

using namespace std;

/**
 * @class Budget
 * @brief This class represents a budget, including its attributes and methods to manage the budget and its spending.
 */
class Budget
{
private:
    string name; ///< The name of the budget.
    int id; ///< The unique identifier for the budget.
    double amount; ///< The total amount allocated for the budget.
    double spentAmount; ///< The total amount spent from the budget.
    std::chrono::system_clock::time_point date; ///< The start date of the budget.
    std::chrono::system_clock::time_point endDate; ///< The end date of the budget.
    string source; ///< The source of the budget (e.g., savings, income, etc.).

public:
    /**
     * @brief Constructor that initializes a new budget with given details.
     * 
     * @param name The name of the budget.
     * @param amount The total amount allocated for the budget.
     * @param date The start date of the budget.
     * @param endDate The end date of the budget.
     * @param source The source of the budget.
     */
    Budget(int id, string name, double amount, double spentAmount, std::chrono::system_clock::time_point date, std::chrono::system_clock::time_point endDate, string source);

    /**
     * @brief Gets the name of the budget.
     * @return The name of the budget.
     */
    string getName() const;

    /**
     * @brief Gets the unique identifier of the budget.
     * @return The ID of the budget.
     */
    int getID() const;

    /**
     * @brief Gets the time interval of the budget (start and end date).
     * @return A string representing the time interval.
     */
    string getTimeInterval() const;

    /**
     * @brief Sets the amount spent from the budget.
     * 
     * @param newSpentAmount The new amount spent from the budget.
     */
    void setSpentAmount(double newSpentAmount);

    /**
     * @brief Gets the total amount spent from the budget.
     * @return The amount spent from the budget.
     */
    double getSpentAmount() const;

    /**
     * @brief Sets the source details for the budget.
     * 
     * @param newSource The new source for the budget.
     */
    void setSourceDetails(string newSource);

    /**
     * @brief Gets the source details of the budget.
     * @return The source of the budget.
     */
    string getSourceDetails() const;

    /**
     * @brief Sets a new start date for the budget.
     * 
     * @param newDate The new start date for the budget.
     */
    std::chrono::system_clock::time_point getStartDate() const;

    /**
     * @brief Sets a new start date for the budget.
     * 
     * @param newDate The new start date for the budget.
     */
    std::chrono::system_clock::time_point getEndDate() const;

    /**
     * @brief Sets a new budget amount.
     * 
     * @param newAmount The new total amount for the budget.
     */
    void setBudgetAmount(double newAmount);

    /**
     * @brief Gets the total amount allocated for the budget.
     * @return The budget amount.
     */
    double getBudgetAmount() const;

    /**
     * @brief Equality operator to compare two budgets.
     * 
     * This operator checks if two budgets are equal by comparing their unique IDs.
     * 
     * @param other The other budget to compare.
     * @return true if the budgets are equal (have the same ID), false otherwise.
     */
    bool operator==(const Budget& other) const {
        return id == other.id;
    }
};

#endif // !BUDGET_H
