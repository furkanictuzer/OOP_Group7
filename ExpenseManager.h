#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include <map>
#include "Expense.h"
#include "Budget.h"
#include "Category.h"

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    std::vector<Budget> budgets;
    double totalExpenses;
    double totalIncome;

public:
    void addExpense(const Expense& expense);
    void removeExpense(const Expense& expense);
    void addIncome(double income);
    double calculateTotalExpenses();
    double calculateTotalIncome();
    std::vector<Expense> filterExpensesByDateRange(const std::string& startDate, const std::string& endDate);
    std::map<Category, double> analyzeExpenseDistributionByCategory();
    double getTotalExpenseByMonth();
};

#endif // EXPENSEMANAGER_H
