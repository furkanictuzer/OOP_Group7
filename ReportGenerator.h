#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include <string>
#include <chrono>
#include "Expense.h"
#include "Category.h"
#include "Report.h"
#include "User.h"

class ReportGenerator {
private:
    std::vector<Report> generatedReports;

public:
    Report generateWeeklyReport(User& user, const std::chrono::system_clock::time_point& startDate);
    Report generateMonthlyReport(User& user, const std::chrono::system_clock::time_point& startDate);
    Report generateAnnualReport(User& user, const std::chrono::system_clock::time_point& startDate);
    Report generateReport(User& user, const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);
    Report generateCategoryReport(const Category& category);
    Report generateCategoryReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const Category& category);
    std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Category>& categories);
    std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Expense*>& expenses);
    std::string reverse(const std::string str);

private:
    std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // REPORTGENERATOR_H