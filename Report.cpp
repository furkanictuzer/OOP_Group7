#include "Report.h"

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

Report::Report(const std::vector<Expense>& expenses, const std::string& start, const std::string& end)
    : expenses(expenses), startDate(start), endDate(end) {}

std::string Report::generateReportDetails() const {
    return "Report Details from " + startDate + " to " + endDate;
}

void Report::generateFile() //Function to generate report file
{
    double totalAmount = 0;
    for (int i = 0; i < expenses.size(); i++)
        totalAmount += this->expenses[i].getAmount();

    std::string fileName = this->startDate + "_" + this->endDate + ".txt";
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        std::cout << "Error opening file! \n" << std::endl;
        return;
    }

    outputFile << generateReportDetails() << "\n";

    outputFile << "Expenses: \n";
    for (int i = 0; i < expenses.size(); i++)
    {
        outputFile << i + 1 << ". " << expenses[i].getExpenseDetails() << "\n";
    }

    map<string, int> categories;
    for (int i = 0; i < expenses.size(); i++)
    {
        categories[(expenses[i].getCategory().getCategoryName())] += expenses[i].getAmount();
    }

    for (const auto& pair : categories)
    {
        outputFile << "-> Category: " << pair.first << " paid amount: " << pair.second << "\n";
    }

    outputFile << "Total expense amount: " << totalAmount << "\n";

    outputFile.close();

    cout << "Report successfully generated. " << endl;
}