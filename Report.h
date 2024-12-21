#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include "Expense.h"

class Report {
private:
    std::vector<Expense> expenses;
    std::string startDate;
    std::string endDate;

public:
    Report(const std::vector<Expense>& expenses, const std::string& start, const std::string& end);

    std::string generateReportDetails() const;

    void generateFile();
};

#endif // REPORT_H