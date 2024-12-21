#include "ReportGenerator.h"
#include "User.h"

Report ReportGenerator::generateWeeklyReport(std::string & startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "07.00.0000"), User::getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "07.00.0000"));
}

Report ReportGenerator::generateMonthlyReport(std::string & startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "00.01.0000"), User::getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "00.01.0000"));
}

Report ReportGenerator::generateAnnualReport(std::string & startDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, DateParser::addDate(startDate, "00.00.0001"), User::getCategories());
    return Report(expenses, startDate, DateParser::addDate(startDate, "00.00.0001"));
}

Report ReportGenerator::generateReport(const std::string& startDate, const std::string& endDate) {
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, User::getCategories());
    return Report(expenses, startDate, endDate);
}

Report ReportGenerator::generateCategoryReport(const Category& category) {
    return Report(category.getExpenses(), "00.00.0000", "31.12.2222");
}

Report ReportGenerator::generateCategoryReport(const std::string& startDate, const std::string& endDate, const Category& category) {
    return Report({}, startDate, endDate);
}

std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::string& startDate,
                                                         const std::string& endDate, vector<Category> categories)
{
    vector<Expense*> relatedExpenses;
    Expense* temp;
    for (int i = 0; i < categories.size(); i++)
    {
        for (int j = 0; j < categories[i].getExpenses().size(); j++)
        {
            temp = categories[i].getExpenses()[j];
            if (reverse(temp->getDate()).compare(reverse(startDate)) >= 0 && 
                                                    reverse(temp->getDate()).compare(reverse(endDate)) <= 0)
            {
                relatedExpenses.push_back(categories[i].getExpenses()[j]);
            }
        }
    }

}

//String format for accurate comparasion should be YYYY.MM.DD
std::string ReportGenerator::reverse(const std::string str)
{
    string result = str;
    for (int i = 0; i < str.length() / 2; i++)
    {
        swap(result[i], result[(str.length() / 2) - i - 1]);
    }
    return result;
}