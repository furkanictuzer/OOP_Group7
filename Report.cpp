#include "Report.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include "DateUtils.h"
using namespace std;

/**
 * @brief Constructor for Report class.
 * 
 * This constructor initializes the report with the list of expenses and the start and end times for the report period.
 * 
 * @param expenses A vector of `Expense` objects that will be included in the report.
 * @param start The start time for the report period.
 * @param end The end time for the report period.
 */
Report::Report(const std::vector<Expense>& expenses, const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end)
    : expenses(expenses), start(start), end(end) {}

/**
 * @brief Generates a detailed string representation of the report.
 * 
 * This function generates a detailed string for the report that includes the expenses and their attributes 
 * such as ID, amount, description, date, and category, within the specified report period.
 * 
 * @return A string containing the report details.
 */
std::string Report::generateReportDetails() const 
{
    if (expenses.empty()) {
        return "";
    }

    std::ostringstream oss;
    std::string startTime = DateUtils::timePointToString(start);
    std::string endTime = DateUtils::timePointToString(end);

    // Report header
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

    // Expense details
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

/**
 * @brief Generates a report file.
 * 
 * This function generates a file that contains the detailed report. The file is named based on the start and end times of the report period.
 */
void Report::generateFile() 
{
    std::string filepath = DateUtils::timePointToString(start) + "_" + DateUtils::timePointToString(end) + "_report";
    std::ofstream outFile(filepath);
    if (outFile.is_open()) {
        outFile << generateReportDetails();
        outFile.close();
    }
}

/**
 * @brief Retrieves the list of expenses in the report.
 * 
 * This function returns the list of expenses that are part of the report.
 * 
 * @return A reference to the vector of `Expense` objects included in the report.
 */
const std::vector<Expense>& Report::getExpenses() const {
    return expenses;
}
