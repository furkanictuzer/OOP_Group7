#ifndef REPORT_H
#define REPORT_H

#include <vector>
#include <string>
#include <chrono>
#include "Expense.h"

/**
 * @class Report
 * @brief Represents a report that aggregates expenses within a specific time period.
 * 
 * This class is used to generate reports that summarize the expenses occurring between a given start and end time.
 * It provides functionality to generate a detailed string report and save the report to a file.
 */
class Report {
private:
    std::vector<Expense> expenses; ///< The list of expenses included in the report.
    std::chrono::system_clock::time_point start; ///< The start time for the report period.
    std::chrono::system_clock::time_point end; ///< The end time for the report period.

public:
    /**
     * @brief Default constructor for Report.
     * 
     * Initializes an empty report.
     */
    Report() {}

    /**
     * @brief Constructs a Report with the specified expenses and time range.
     * 
     * @param expenses The list of expenses included in the report.
     * @param start The start time for the report period.
     * @param end The end time for the report period.
     */
    Report(const std::vector<Expense>& expenses, const std::chrono::system_clock::time_point& start, const std::chrono::system_clock::time_point& end);

    /**
     * @brief Generates a detailed string of the report.
     * 
     * This method generates a summary report of all expenses within the specified time period.
     * 
     * @return A string containing the details of the report.
     */
    std::string generateReportDetails() const;

    /**
     * @brief Generates and saves the report to a file.
     * 
     * This method creates a file containing the details of the report, which can be saved for future reference.
     */
    void generateFile();

    /**
     * @brief Retrieves the expenses included in the report.
     * 
     * This method returns the list of expenses associated with the report.
     * 
     * @return A constant reference to the vector of expenses.
     */
    const std::vector<Expense>& getExpenses() const;
};

#endif // REPORT_H
