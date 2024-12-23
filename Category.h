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
    const std::vector<Expense*>& getExpenses() const;
    void setCategoryName(const std::string& name);

    // Overload the '<' operator to enable comparison between Category objects
    bool operator<(const Category& other) const {
        // Example: Compare by the 'name' attribute (adjust this based on your class design)
        return this->name < other.name;
    }
};

#endif // CATEGORY_H
