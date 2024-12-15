#include "ReportGenerator.h"

Report ReportGenerator::generateWeeklyReport() {
    return Report({}, "weekly_start", "weekly_end");
}

Report ReportGenerator::generateMonthlyReport() {
    return Report({}, "monthly_start", "monthly_end");
}

Report ReportGenerator::generateAnnualReport() {
    return Report({}, "annual_start", "annual_end");
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
