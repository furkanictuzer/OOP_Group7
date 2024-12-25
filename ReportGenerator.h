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

class ReportGenerator {
public:
    static Report generateWeeklyReport(const std::chrono::system_clock::time_point& startDate);
    static Report generateMonthlyReport(const std::chrono::system_clock::time_point& startDate);
    static Report generateAnnualReport(const std::chrono::system_clock::time_point& startDate);
    static Report generateReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate);
    static Report generateCategoryReport(const Category& category);
    static Report generateCategoryReport(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const Category& category);
    static std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Category>& categories);
    static std::vector<Expense> getRelatedExpenses(const std::chrono::system_clock::time_point& startDate, const std::chrono::system_clock::time_point& endDate, const std::vector<Expense*>& expenses);
    static std::string reverse(const std::string str);

private:
    static std::chrono::system_clock::time_point stringToTimePoint(const std::string& timeStr);
};

#endif // REPORTGENERATOR_H