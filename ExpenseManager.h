#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <map>
#include <chrono>
#include "Expense.h"
#include "Budget.h"
#include "Category.h"

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    std::vector<Budget> budgets;
    double totalExpenses = 0;
    double totalIncome = 0;

public:
    void addExpense(const Expense& expense);
    void removeExpense(const Expense& expense);
    void addIncome(double income);
    double calculateTotalExpenses();
    double calculateTotalIncome();
    std::vector<Expense> filterExpensesByDateRange(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);
    std::map<Category, double> analyzeExpenseDistributionByCategory();
    double getTotalExpenseByMonth(int month, int year);

private:
    std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // EXPENSEMANAGER_H
