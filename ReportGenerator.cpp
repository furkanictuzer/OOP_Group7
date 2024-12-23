#include "ReportGenerator.h"
#include "User.h"
#include "DateUtils.h"
#include <sstream>
#include <iomanip>

Report ReportGenerator::generateWeeklyReport(User& user, const std::chrono::system_clock::time_point& startDate) {
    auto endDate = startDate + std::chrono::hours(24 * 7);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateMonthlyReport(User& user, const std::chrono::system_clock::time_point& startDate) {
    auto endDate = startDate + std::chrono::hours(24 * 30);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateAnnualReport(User& user, const std::chrono::system_clock::time_point& startDate) {
    auto endDate = startDate + std::chrono::hours(24 * 365);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateReport(User& user, const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateCategoryReport(const Category& category) {
    std::vector<Expense> expenses;
    for (const auto& expense : category.getExpenses()) {
        expenses.push_back(*expense);
    }
    auto start = DateUtils::stringToTimePoint("01.01.0000");
    auto end = DateUtils::stringToTimePoint("31.12.2222");
    return Report(expenses, start, end);
}

Report ReportGenerator::generateCategoryReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const Category& category) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, category.getExpenses());
    return Report(expenses, startDate, endDate);
}

std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Category>& categories) {
    std::vector<Expense> relatedExpenses;
    for (const auto& category : categories) {
        for (const auto& expense : category.getExpenses()) {
            if (expense->getDate() >= startDate && expense->getDate() <= endDate) {
                relatedExpenses.push_back(*expense);
            }
        }
    }
    return relatedExpenses;
}

std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Expense*>& expenses) {
    std::vector<Expense> relatedExpenses;
    for (const auto& expense : expenses) {
        if (expense->getDate() >= startDate && expense->getDate() <= endDate) {
            relatedExpenses.push_back(*expense);
        }
    }
    return relatedExpenses;
}