#include "ReportGenerator.h"
#include "User.h"

Report ReportGenerator::generateWeeklyReport(User& user, std::string& startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "07.00.0000"), user.getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "07.00.0000"));
}

Report ReportGenerator::generateMonthlyReport(User& user, std::string& startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "00.01.0000"), user.getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "00.01.0000"));
}

Report ReportGenerator::generateAnnualReport(User& user, std::string& startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "00.00.0001"), user.getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "00.00.0001"));
}

Report ReportGenerator::generateReport(User& user, const std::string& startDate, const std::string& endDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateCategoryReport(const Category& category) {
    //return Report(category.getExpenses(), "00.00.0000", "31.12.2222");
    std::vector<Expense> expenses;
    for (const auto& expense : category.getExpenses()) {
        expenses.push_back(*expense);
    }
    return Report(expenses, "00.00.0000", "31.12.2222");
}

Report ReportGenerator::generateCategoryReport(const std::string& startDate, const std::string& endDate, const Category& category) {
    return Report({}, startDate, endDate);
}

std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::string& startDate, const std::string& endDate, std::vector<Category> categories) {
    std::vector<Expense> relatedExpenses;
    for (const auto& category : categories)
    {
        for (const auto& expense : category.getExpenses())
        {
            if (reverse(expense->getDate()).compare(reverse(startDate)) >= 0 && 
                reverse(expense->getDate()).compare(reverse(endDate)) <= 0)
            {
                relatedExpenses.push_back(*expense);
            }
        }
    }
    return relatedExpenses;
}

// String format for accurate comparison should be YYYY.MM.DD
std::string ReportGenerator::reverse(const std::string str)
{
    std::string result = str;
    for (int i = 0; i < str.length() / 2; i++)
    {
        std::swap(result[i], result[str.length() - i - 1]);
    }
    return result;
}