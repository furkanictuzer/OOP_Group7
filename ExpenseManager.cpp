#include "ExpenseManager.h"

void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void ExpenseManager::removeExpense(const Expense& expense) {

}

void ExpenseManager::addIncome(double income) {
    totalIncome += income;
}

double ExpenseManager::calculateTotalExpenses() {
    totalExpenses = 0;
    for (const auto& exp : expenses) {
        totalExpenses += exp.getAmount() ;
    }
    return totalExpenses;
}

double ExpenseManager::calculateTotalIncome() {
    return totalIncome;
}

std::vector<Expense> ExpenseManager::filterExpensesByDateRange(const std::string& startDate, const std::string& endDate) {
    std::vector<Expense> filtered;
    return filtered;
}

std::map<Category, double> ExpenseManager::analyzeExpenseDistributionByCategory() {
    std::map<Category, double> distribution;
    return distribution;
}

double ExpenseManager::getTotalExpenseByMonth() {
    return ;
}
