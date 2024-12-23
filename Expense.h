#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include <chrono>
#include "Category.h"

// Forward declaration
class Category;

class Expense {
private:
    int id;
    double amount;
    std::chrono::system_clock::time_point date; // Use chrono for date
    Category* category;
    std::string description;

public:
    Expense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category);
    void setExpenseDetails(double amount, const std::string& description);
    std::string getExpenseDetails() const;
    double getAmount() const;
    int getId() const;
    std::chrono::system_clock::time_point getDate() const;
    Category* getCategory() const; // Marked as const
    std::string getDescription() const;

    // operator== tanımı
    bool operator==(const Expense& other) const;
};

#endif // EXPENSE_H
