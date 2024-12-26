#include "ReportGenerator.h"
#include "User.h"
#include "DateUtils.h"
#include <sstream>
#include <iomanip>

/**
 * @brief Generates a weekly report based on the provided start date.
 * 
 * This function generates a report for the week starting from the specified start date. 
 * It retrieves all related expenses within the week and returns a `Report` object.
 * 
 * @param startDate The start date for the weekly report.
 * @return A `Report` object containing the related expenses within the week.
 */
Report ReportGenerator::generateWeeklyReport(const std::chrono::system_clock::time_point& startDate) 
{
    User user = FileManager::getMainUser();
    auto endDate = startDate + std::chrono::hours(24 * 7);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

/**
 * @brief Generates a monthly report based on the provided start date.
 * 
 * This function generates a report for the month starting from the specified start date.
 * It retrieves all related expenses within the month and returns a `Report` object.
 * 
 * @param startDate The start date for the monthly report.
 * @return A `Report` object containing the related expenses within the month.
 */
Report ReportGenerator::generateMonthlyReport(const std::chrono::system_clock::time_point& startDate) 
{
    User user = FileManager::getMainUser();
    auto endDate = startDate + std::chrono::hours(24 * 30);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

/**
 * @brief Generates an annual report based on the provided start date.
 * 
 * This function generates a report for the year starting from the specified start date. 
 * It retrieves all related expenses within the year and returns a `Report` object.
 * 
 * @param startDate The start date for the annual report.
 * @return A `Report` object containing the related expenses within the year.
 */
Report ReportGenerator::generateAnnualReport(const std::chrono::system_clock::time_point& startDate) 
{
    User user = FileManager::getMainUser();
    auto endDate = startDate + std::chrono::hours(24 * 365);
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

/**
 * @brief Generates a report for a custom date range.
 * 
 * This function generates a report for the specified date range. 
 * It retrieves all related expenses within the given start and end dates and returns a `Report` object.
 * 
 * @param startDate The start date for the report.
 * @param endDate The end date for the report.
 * @return A `Report` object containing the related expenses within the custom date range.
 */
Report ReportGenerator::generateReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate) 
{
    User user = FileManager::getMainUser();
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, user.getCategories());
    return Report(expenses, startDate, endDate);
}

/**
 * @brief Generates a report for a specific category.
 * 
 * This function generates a report for all expenses related to a specific category, including all time periods.
 * The start and end times are set to an infinite range.
 * 
 * @param category The category for which the report is generated.
 * @return A `Report` object containing the related expenses for the specified category.
 */
Report ReportGenerator::generateCategoryReport(const Category& category) 
{
    std::vector<Expense> expenses;
    for (const auto& expense : category.getExpenses()) {
        expenses.push_back(*expense);
    }
    auto start = DateUtils::stringToTimePoint("01.01.0000");
    auto end = DateUtils::stringToTimePoint("31.12.2222");
    return Report(expenses, start, end);
}

/**
 * @brief Generates a report for a specific category within a custom date range.
 * 
 * This function generates a report for all expenses related to a specific category within the provided date range.
 * 
 * @param startDate The start date for the report.
 * @param endDate The end date for the report.
 * @param category The category for which the report is generated.
 * @return A `Report` object containing the related expenses for the specified category and date range.
 */
Report ReportGenerator::generateCategoryReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const Category& category) 
{
    std::vector<Expense> expenses = getRelatedExpenses(startDate, endDate, category.getExpenses());
    return Report(expenses, startDate, endDate);
}

/**
 * @brief Retrieves expenses related to a specific date range and categories.
 * 
 * This function retrieves the expenses that fall within the specified date range and belong to the given categories.
 * 
 * @param startDate The start date for the date range.
 * @param endDate The end date for the date range.
 * @param categories The list of categories to filter expenses by.
 * @return A vector of `Expense` objects related to the date range and categories.
 */
std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Category>& categories) 
{
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

/**
 * @brief Retrieves expenses related to a specific date range and a list of expenses.
 * 
 * This function retrieves the expenses that fall within the specified date range from a list of expenses.
 * 
 * @param startDate The start date for the date range.
 * @param endDate The end date for the date range.
 * @param expenses The list of expenses to filter by date range.
 * @return A vector of `Expense` objects related to the date range.
 */
std::vector<Expense> ReportGenerator::getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Expense*>& expenses) 
{
    std::vector<Expense> relatedExpenses;
    for (const auto& expense : expenses) {
        if (expense->getDate() >= startDate && expense->getDate() <= endDate) {
            relatedExpenses.push_back(*expense);
        }
    }
    return relatedExpenses;
}
