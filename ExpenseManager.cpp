#include "ExpenseManager.h"
#include "DateParser.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

std::vector<Expense> ExpenseManager::expenses;
std::vector<Budget> ExpenseManager::budgets;
double ExpenseManager::totalExpenses = 0;
double ExpenseManager::totalIncome = 0;

void ExpenseManager::addExpense(const Expense& expense) {
    User& user = FileManager::getMainUser();

    // Create a new Expense object on the heap and pass a pointer to it
    Expense* newExpense = new Expense(expense);
    user.getCategoryByName(expense.getCategory()->getCategoryName())->addExpense(newExpense);

    expenses.push_back(*newExpense);

    FileManager::saveDataToFile(&user);
}

void ExpenseManager::removeExpense(const Expense& expense) {
    expenses.erase(std::remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

void ExpenseManager::addBudget(const Budget& budget) {
    User& user = FileManager::getMainUser();

    user.addBudget(budget);

    budgets.push_back(budget);

    FileManager::saveDataToFile(&user);
}

void ExpenseManager::removeBudget(const Budget& budget) {
    budgets.erase(std::remove(budgets.begin(), budgets.end(), budget), budgets.end());
}

std::vector<Expense> ExpenseManager::getExpenses() {
    return expenses;
}

std::vector<Budget> ExpenseManager::getBudgets() {
    return budgets;
}

double ExpenseManager::calculateTotalExpenses() {
    totalExpenses = 0;
    for (const auto& exp : expenses) {
        totalExpenses += exp.getAmount();
    }
    User& user = FileManager::getMainUser();
    user.getCurrentBudget().setSpentAmount(totalExpenses);
    return totalExpenses;
}

double ExpenseManager::calculateTotalIncome() {
    return totalIncome;
}

std::vector<Expense> ExpenseManager::filterExpensesByDateRange(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate) {
    std::vector<Expense> filtered;
    for (const auto& expense : expenses) {
        if (expense.getDate() >= startDate && expense.getDate() <= endDate) {
            filtered.push_back(expense);
        }
    }
    return filtered;
}

std::map<Category, double> ExpenseManager::analyzeExpenseDistributionByCategory() {
    std::map<Category, double> distribution;
    for (const auto& expense : expenses) {
        distribution[*expense.getCategory()] += expense.getAmount();
    }
    return distribution;
}

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

std::chrono::system_clock::time_point ExpenseManager::stringToTimePoint(const std::string& timeStr) {
    // Implement the conversion from string to time_point
    // This is just a placeholder implementation
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::time_t time = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(time);
}
