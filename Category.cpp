#include "Category.h"

Category::Category(const std::string& name) : name(name) {}

void Category::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

void Category::removeExpense(const Expense& expense) {

}

std::string Category::getCategoryName() const {
    return name;
}

void Category::setCategoryName(const std::string& newName) {
    this->name = newName;
}
