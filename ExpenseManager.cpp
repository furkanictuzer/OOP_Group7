#include "ExpenseManager.h"
#include "DateParser.h"
#include "FileManager.h"
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <iostream>

std::vector<Expense> ExpenseManager::expenses;
std::vector<Budget> ExpenseManager::budgets;
double ExpenseManager::totalExpenses = 0;
double ExpenseManager::totalIncome = 0;

/**
 * @brief Adds an expense to the user's expenses and updates the budget.
 * 
 * This function creates a new expense and adds it to the user's selected category.
 * If a budget is available, it updates the spent amount of the budget.
 * After that, the new expense is saved to the file system.
 * 
 * @param expense The expense to be added.
 */
void ExpenseManager::addExpense(const Expense& expense) {
    User& user = FileManager::getMainUser();

    std::cout << "Adding expense: " << expense.getDescription() << std::endl;

    // Create a new Expense object on the heap and pass a pointer to it
    Expense* newExpense = new Expense(expense);
    std::cout << "New expense created." << std::endl;

    Category* category = user.getCategoryByName(expense.getCategory()->getCategoryName());
    if (!category) {
        std::cerr << "Error: Category not found." << std::endl;
        delete newExpense;
        return;
    }
    std::cout << "Category found: " << category->getCategoryName() << std::endl;

    category->addExpense(newExpense);
    std::cout << "Expense added to category." << std::endl;

    try {
        Budget& budget = user.getCurrentBudget();
        budget.setSpentAmount(budget.getSpentAmount() + expense.getAmount()); // Update spent amount in the budget
        std::cout << "Budget updated. Spent amount: " << budget.getSpentAmount() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "No current budget found. Skipping budget update. Error: " << e.what() << std::endl;
    }

    expenses.push_back(*newExpense);
    std::cout << "Expense added to ExpenseManager." << std::endl;

    FileManager::saveDataToFile(&user);
    std::cout << "Data saved to file." << std::endl;
}

/**
 * @brief Removes an expense from the list of expenses.
 * 
 * This function removes the specified expense from the expenses list using the
 * `std::remove` function.
 * 
 * @param expense The expense to be removed.
 */
void ExpenseManager::removeExpense(const Expense& expense) {
    expenses.erase(std::remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

/**
 * @brief Adds a budget to the user's list of budgets.
 * 
 * This function adds the provided budget to the user's budget list and saves
 * the updated data to the file.
 * 
 * @param budget The budget to be added.
 */
void ExpenseManager::addBudget(const Budget& budget) {
    User& user = FileManager::getMainUser();

    user.addBudget(budget);

    budgets.push_back(budget);

    FileManager::saveDataToFile(&user);
}

/**
 * @brief Removes a budget from the list of budgets.
 * 
 * This function removes the specified budget from the budgets list using the
 * `std::remove` function.
 * 
 * @param budget The budget to be removed.
 */
void ExpenseManager::removeBudget(const Budget& budget) {
    budgets.erase(std::remove(budgets.begin(), budgets.end(), budget), budgets.end());
}

/**
 * @brief Retrieves all expenses.
 * 
 * This function returns the list of all expenses managed by the `ExpenseManager`.
 * 
 * @return A vector containing all expenses.
 */
std::vector<Expense> ExpenseManager::getExpenses() {
    return expenses;
}

/**
 * @brief Retrieves all budgets.
 * 
 * This function returns the list of all budgets managed by the `ExpenseManager`.
 * 
 * @return A vector containing all budgets.
 */
std::vector<Budget> ExpenseManager::getBudgets() {
    return budgets;
}

/**
 * @brief Calculates the total amount of expenses.
 * 
 * This function sums up all the expenses and updates the spent amount of the
 * current budget based on the total expenses.
 * 
 * @return The total amount of expenses.
 */
double ExpenseManager::calculateTotalExpenses() {
    totalExpenses = 0;
    for (const auto& exp : expenses) {
        totalExpenses += exp.getAmount();
    }
    User& user = FileManager::getMainUser();
    user.getCurrentBudget().setSpentAmount(totalExpenses);
    return totalExpenses;
}

/**
 * @brief Retrieves the total income.
 * 
 * This function returns the total income, though it is currently set to return
 * a static value.
 * 
 * @return The total income.
 */
double ExpenseManager::calculateTotalIncome() {
    return totalIncome;
}

/**
 * @brief Filters expenses within a specified date range.
 * 
 * This function filters the expenses that fall within the given date range.
 * 
 * @param startDate The start date of the range.
 * @param endDate The end date of the range.
 * 
 * @return A vector containing the filtered expenses.
 */
std::vector<Expense> ExpenseManager::filterExpensesByDateRange(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate) {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        if (expense.getDate() >= startDate && expense.getDate() <= endDate) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

/**
 * @brief Analyzes the expense distribution by category.
 * 
 * This function calculates the total expenses for each category and returns
 * a map containing the category and the corresponding total amount spent.
 * 
 * @return A map where keys are categories and values are the total amounts spent.
 */
std::map<Category, double> ExpenseManager::analyzeExpenseDistributionByCategory() {
    std::map<Category, double> distribution;
    for (const auto& expense : expenses) {
        distribution[*expense.getCategory()] += expense.getAmount();
    }
    return distribution;
}

/**
 * @brief Retrieves the total expenses for a specific month and year.
 * 
 * This function calculates the total expenses for the given month and year.
 * 
 * @param month The month for which the total expenses are to be calculated.
 * @param year The year for which the total expenses are to be calculated.
 * 
 * @return The total amount spent during the specified month and year.
 */
double ExpenseManager::getTotalExpenseByMonth(int month, int year) {
    std::vector<Expense> monthExpenses;

    for (const auto& expense : expenses) {
        auto date = expense.getDate();
        std::time_t time = std::chrono::system_clock::to_time_t(date);
        std::tm* tm = std::localtime(&time);

        if (tm->tm_year + 1900 == year && tm->tm_mon + 1 == month) {
            monthExpenses.push_back(expense);
        }
    }

    double total = 0;
    for (const auto& expense : monthExpenses) {
        total += expense.getAmount();
    }
    return total;
}
