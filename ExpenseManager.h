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

class ExpenseManager {
private:
    static User* user;
    static std::vector<Expense> expenses;
    static std::vector<Budget> budgets;
    static double totalExpenses;
    static double totalIncome;

public:
    ExpenseManager(User* user);
    static void addExpense(const Expense& expense);
    static void removeExpense(const Expense& expense);
    static void addIncome(double income);
    static double calculateTotalExpenses();
    static double calculateTotalIncome();
    static std::vector<Expense> filterExpensesByDateRange(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);
    static std::map<Category, double> analyzeExpenseDistributionByCategory();
    static double getTotalExpenseByMonth(int month, int year);

private:
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // EXPENSEMANAGER_H
