#include "ReportGenerator.h"

Report ReportGenerator::generateWeeklyReport(std::string & startDate) {
    return Report({}, startDate, DateParser::addDate(startDate, "07.00.0000"));
}

Report ReportGenerator::generateMonthlyReport(std::string & startDate) {
    return Report({}, startDate, DateParser::addDate(startDate, "00.01.0000"));
}

Report ReportGenerator::generateAnnualReport(std::string & startDate) {
    return Report({}, startDate, DateParser::addDate(startDate, "00.00.0001"));
}

Report ReportGenerator::generateReport(const std::string& startDate, const std::string& endDate) {
    return Report({}, startDate, endDate);
}

Report ReportGenerator::generateCategoryReport(const Category& category) {
    return Report({}, "category_start", "category_end");
}

Report ReportGenerator::generateCategoryReport(const std::string& startDate, const std::string& endDate, const Category& category) {
    return Report({}, startDate, endDate);
}