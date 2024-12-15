#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>
#include "Expense.h"

class Category {
private:
    std::string name;
    std::vector<Expense> expenses;

public:
    Category(const std::string& name);
    void addExpense(const Expense& expense);
    void removeExpense(const Expense& expense);
    std::string getCategoryName() const;
    void setCategoryName(const std::string& name);
};

#endif // CATEGORY_H
