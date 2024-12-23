#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Category.h"

// Forward declaration
class Category;

class Expense {
private:
    int id;
    double amount;
    std::string date;//Date format : DD.MM.YYYY
    Category* category;
    std::string description;

public:
    Expense(int id, double amount, const std::string& date, const std::string& description, Category* category);
    void setExpenseDetails(double amount, const std::string& description);
    std::string getExpenseDetails() const;
    double getAmount() const;
    int getId() const;
    std::string getDate() const;
    Category* getCategory();
    std::string getDescription() const;

    // operator== tanımı
    bool operator==(const Expense& other) const;
};

#endif // EXPENSE_H
