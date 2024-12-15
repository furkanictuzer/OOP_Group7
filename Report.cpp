#include "Report.h"

Report::Report(const std::vector<Expense>& expenses, const std::string& start, const std::string& end)
    : expenses(expenses), startDate(start), endDate(end) {}

std::string Report::generateReportDetails() const {
    return "Report Details from " + startDate + " to " + endDate;
}
