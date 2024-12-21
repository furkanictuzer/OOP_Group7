#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

// Forward declaration
class Expense;

class Category {
private:
    std::string name;
    std::vector<Expense*> expenses;

public:
    Category(const std::string& name);
    void addExpense(Expense* expense);
    void removeExpense(Expense* expense);
    std::string getCategoryName() const;
    void setCategoryName(const std::string& name);
};

#endif // CATEGORY_H
