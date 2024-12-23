#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>
#include <chrono>
#include "Expense.h"

class Report {
private:
    std::vector<Expense> expenses;
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point end;

public:
    Report(const std::vector<Expense>& expenses, const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end);

    std::string generateReportDetails() const;
    void generateFile();

    // New method to get expenses
    const std::vector<Expense>& getExpenses() const;
};

#endif // REPORT_H