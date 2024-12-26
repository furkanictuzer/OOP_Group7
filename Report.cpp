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

std::string Report::generateReportDetails() const 
{
    if (expenses.empty())
    {
        return "";
    }    

    std::ostringstream oss;
    std::string startTime = DateUtils::timePointToString(start);
    std::string endTime = DateUtils::timePointToString(end);    

    oss << "Report from " << startTime
        << " to " << endTime << "\n";
    oss << "------------------------------------------------------------------------------------------------------------------------\n";
    oss << std::left << std::setw(10) << "ID"
        << std::setw(15) << "Amount"
        << std::setw(30) << "Description"
        << std::setw(20) << "Date"
        << std::setw(20) << "Category"
        << "\n";
    oss << "------------------------------------------------------------------------------------------------------------------------\n";
    for (const auto& expense : expenses) {
        std::time_t expenseTime = std::chrono::system_clock::to_time_t(expense.getDate());
        oss << std::left << std::setw(10) << expense.getId()
            << std::setw(15) << std::fixed << std::setprecision(2) << expense.getAmount()
            << std::setw(30) << expense.getDescription()
            << std::setw(20) << std::put_time(std::localtime(&expenseTime), "%Y-%m-%d")
            << std::setw(20) << expense.getCategory()->getCategoryName()
            << "\n";
    }
    return oss.str();
}

void Report::generateFile() //Function to generate report file
{
    std::string filepath = DateUtils::timePointToString(start) + "_" + DateUtils::timePointToString(end) + "_report";
    std::ofstream outFile(filepath);
    if (outFile.is_open()) {
        outFile << generateReportDetails();
        outFile.close();
    }
}

const std::vector<Expense>& Report::getExpenses() const {
    return expenses;
}