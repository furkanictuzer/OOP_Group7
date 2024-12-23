#include "Report.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include "DateUtils.h"
using namespace std;

Report::Report(const std::vector<Expense>& expenses, const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end)
    : expenses(expenses), start(start), end(end) {}

// Example usage of the helper function
void exampleUsage() {
    std::string startTimeStr = "2021.05.01";
    std::string endTimeStr = "2021.05.07";
    auto startTime = DateUtils::stringToTimePoint(startTimeStr);
    auto endTime = DateUtils::stringToTimePoint(endTimeStr);

    std::vector<Expense> expenses;
    Report report(expenses, startTime, endTime);
}

std::string Report::generateReportDetails() const {
    std::ostringstream oss;
    std::time_t startTime = std::chrono::system_clock::to_time_t(start);
    std::time_t endTime = std::chrono::system_clock::to_time_t(end);
    oss << "Report from " << std::put_time(std::localtime(&startTime), "%Y-%m-%d")
        << " to " << std::put_time(std::localtime(&endTime), "%Y-%m-%d") << "\n";
    for (const auto& expense : expenses) {
        oss << "ID: " << expense.getId() << ", Amount: " << expense.getAmount() << ", Description: " << expense.getDescription() << "\n";
    }
    return oss.str();
}

void Report::generateFile() //Function to generate report file
{
    std::ofstream outFile("report.txt");
    if (outFile.is_open()) {
        outFile << generateReportDetails();
        outFile.close();
    }
}

const std::vector<Expense>& Report::getExpenses() const {
    return expenses;
}