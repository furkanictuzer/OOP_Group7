#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <map>
#include <chrono>
#include "Expense.h"
#include "Budget.h"
#include "Category.h"
#include "FileManager.h"
#include "User.h"

/**
 * @class ExpenseManager
 * @brief Manages expenses, budgets, and their related operations.
 * 
 * This class provides functionality to add, remove, and retrieve expenses and budgets.
 * It also supports calculating total expenses, analyzing expenses by category, and filtering
 * expenses by a specific date range.
 */
class ExpenseManager {
private:
    static std::vector<Expense> expenses; ///< List of all expenses.
    static std::vector<Budget> budgets; ///< List of all budgets.
    static double totalExpenses; ///< Total of all expenses.
    static double totalIncome; ///< Total of all income.

public:
    /**
     * @brief Adds a new expense to the expense list.
     * @param expense The expense to be added.
     */
    static void addExpense(const Expense& expense);

    /**
     * @brief Removes an expense from the expense list.
     * @param expense The expense to be removed.
     */
    static void removeExpense(const Expense& expense);

    /**
     * @brief Adds a new budget to the budget list.
     * @param budget The budget to be added.
     */
    static void addBudget(const Budget& budget);

    /**
     * @brief Removes a budget from the budget list.
     * @param budget The budget to be removed.
     */
    static void removeBudget(const Budget& budget);

    /**
     * @brief Retrieves all expenses.
     * @return A vector containing all expenses.
     */
    static std::vector<Expense> getExpenses();

    /**
     * @brief Retrieves all budgets.
     * @return A vector containing all budgets.
     */
    static std::vector<Budget> getBudgets();

    /**
     * @brief Calculates the total expenses.
     * @return The sum of all expenses.
     */
    static double calculateTotalExpenses();

    /**
     * @brief Calculates the total income.
     * @return The sum of all income.
     */
    static double calculateTotalIncome();

    /**
     * @brief Filters expenses by a specified date range.
     * @param startDate The start date of the range.
     * @param endDate The end date of the range.
     * @return A vector containing the expenses within the date range.
     */
    static std::vector<Expense> filterExpensesByDateRange(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);

    /**
     * @brief Analyzes the expense distribution by category.
     * @return A map of categories and their corresponding total expense amounts.
     */
    static std::map<Category, double> analyzeExpenseDistributionByCategory();

    /**
     * @brief Retrieves the total expense for a specific month and year.
     * @param month The month to calculate total expenses for.
     * @param year The year to calculate total expenses for.
     * @return The total expense for the given month and year.
     */
    static double getTotalExpenseByMonth(int month, int year);

private:
    /**
     * @brief Converts a string representation of a time to a system clock time_point.
     * @param timeStr The string representation of the time.
     * @return The corresponding time_point.
     */
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // EXPENSEMANAGER_H
