#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Category.h"

class Expense {
private:
    int id;
    double amount;
    std::string date;//Date format : DD.MM.YYYY
    Category category;
    std::string description;

public:
    Expense(int id, double amount, const std::string& date, const std::string& description, const Category& category);
    void setExpenseDetails(double amount, const std::string& description);
    std::string getExpenseDetails() const;
    double getAmount() const;
    std::string getDate() const;
};

#endif // EXPENSE_H
