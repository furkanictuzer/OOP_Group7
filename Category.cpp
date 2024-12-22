#include "Category.h"
#include <algorithm>
#include "Expense.h"

Category::Category(const std::string& name) : name(name) {}

void Category::addExpense(Expense* expense) {
    expenses.push_back(expense);
}

void Category::removeExpense(Expense* expense) {
    expenses.erase(std::remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

std::string Category::getCategoryName() const {
    return name;
}

void Category::setCategoryName(const std::string& newName) {
    this->name = newName;
}

const std::vector<Expense*>& Category::getExpenses() const {
    return expenses;
}