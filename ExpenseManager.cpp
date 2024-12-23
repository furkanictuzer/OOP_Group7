#include "ExpenseManager.h"
#include "DateParser.h"
#include <algorithm>
#include <sstream>
#include <iomanip>

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void ExpenseManager::removeExpense(const Expense& expense) {
    expenses.erase(std::remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

void ExpenseManager::addIncome(double income) {
    totalIncome += income;
}

double ExpenseManager::calculateTotalExpenses() {
    totalExpenses = 0;
    for (const auto& exp : expenses) {
        totalExpenses += exp.getAmount();
    }
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

    double totalExpense = 0;
    for (const auto& expense : monthExpenses) {
        totalExpense += expense.getAmount();
    }
    return totalExpense;
}

// Helper function to convert string to time_point
std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr) {
    std::tm tm = {};
    std::istringstream ss(timeStr);
    ss >> std::get_time(&tm, "%Y.%m.%d");
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}
