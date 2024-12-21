#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <vector>
#include "Report.h"
#include "Category.h"
#include "DateParser.h"

class ReportGenerator {
private:
    std::vector<Report> generatedReports;

public:
    Report generateWeeklyReport(std::string& startDate);
    Report generateMonthlyReport(std::string & startDate);
    Report generateAnnualReport(std::string & startDate);
    Report generateReport(const std::string& startDate, const std::string& endDate);
    Report generateCategoryReport(const Category& category);
    Report generateCategoryReport(const std::string& startDate, const std::string& endDate, const Category& category);
};

#endif // REPORTGENERATOR_H