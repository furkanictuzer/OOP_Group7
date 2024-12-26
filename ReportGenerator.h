#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>
#include <chrono>
#include "Expense.h"
#include "Category.h"
#include "Report.h"
#include "User.h"
#include "DateUtils.h"
#include "FileManager.h"

/**
 * @class ReportGenerator
 * @brief Provides functionality to generate various types of reports based on expenses and categories.
 * 
 * This class includes methods to generate reports for different time periods (weekly, monthly, annual)
 * and for specific categories of expenses. It also provides functionality to retrieve related expenses
 * for a given time range and category.
 */
class ReportGenerator {
public:
    /**
     * @brief Generates a weekly report starting from the given start date.
     * 
     * @param startDate The start date for the report.
     * @return A Report object containing weekly expense data.
     */
    static Report generateWeeklyReport(const std::chrono::system_clock::time_point& startDate);

    /**
     * @brief Generates a monthly report starting from the given start date.
     * 
     * @param startDate The start date for the report.
     * @return A Report object containing monthly expense data.
     */
    static Report generateMonthlyReport(const std::chrono::system_clock::time_point& startDate);

    /**
     * @brief Generates an annual report starting from the given start date.
     * 
     * @param startDate The start date for the report.
     * @return A Report object containing annual expense data.
     */
    static Report generateAnnualReport(const std::chrono::system_clock::time_point& startDate);

    /**
     * @brief Generates a report for a specific time range.
     * 
     * @param startDate The start date for the report.
     * @param endDate The end date for the report.
     * @return A Report object containing expense data for the specified time range.
     */
    static Report generateReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);

    /**
     * @brief Generates a report for a specific category.
     * 
     * @param category The category for which the report should be generated.
     * @return A Report object containing expenses for the specified category.
     */
    static Report generateCategoryReport(const Category& category);

    /**
     * @brief Generates a report for a specific category within a time range.
     * 
     * @param startDate The start date for the report.
     * @param endDate The end date for the report.
     * @param category The category for which the report should be generated.
     * @return A Report object containing expenses for the specified category within the time range.
     */
    static Report generateCategoryReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const Category& category);

    /**
     * @brief Retrieves the expenses related to a given time range and categories.
     * 
     * @param startDate The start date for the expenses to be retrieved.
     * @param endDate The end date for the expenses to be retrieved.
     * @param categories The categories for which expenses should be retrieved.
     * @return A vector of expenses that are related to the time range and categories.
     */
    static std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Category>& categories);

    /**
     * @brief Retrieves the expenses related to a given time range and expense list.
     * 
     * @param startDate The start date for the expenses to be retrieved.
     * @param endDate The end date for the expenses to be retrieved.
     * @param expenses A vector of Expense pointers for which the related expenses should be retrieved.
     * @return A vector of expenses that are related to the time range and provided expenses.
     */
    static std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Expense*>& expenses);

    /**
     * @brief Reverses a given string.
     * 
     * @param str The string to be reversed.
     * @return The reversed string.
     */
    static std::string reverse(const std::string str);

private:
    /**
     * @brief Converts a string representation of a date to a time_point object.
     * 
     * @param timeStr The string representing the date to be converted.
     * @return A time_point object corresponding to the string date.
     */
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // REPORTGENERATOR_H
