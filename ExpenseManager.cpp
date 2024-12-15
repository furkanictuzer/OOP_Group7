#include "ExpenseManager.h"
#include "DateParser.h"
#include <algorithm>

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

double ExpenseManager::getTotalExpenseByMonth(int month, int year) {
    
    vector<Expense> monthExpenses;

    for (size_t i = 0; i < expenses.size(); i++)
    {
        Expense& expense = expenses[i];

        int expenseDay;
        int expenseMonth;
        int expenseYear;
        string date = expense.getDate();

        DateParser::parseDate(date, expenseDay, expenseMonth, expenseYear);

        if (expenseYear == year && month == expenseMonth)
        {
            monthExpenses.push_back(expense);
        }
    }

    double totalExpense = 0;

    for (size_t i = 0; i < monthExpenses.size(); i++)
    {
        totalExpense += monthExpenses[i].getAmount();
    }   
    

    return totalExpense;
}
