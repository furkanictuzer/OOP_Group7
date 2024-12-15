#include "Expense.h"

Expense::Expense(int id, double amount, const std::string& date, const std::string& description, const Category& category)
    : id(id), amount(amount), date(date), description(description), category(category) {}

void Expense::setExpenseDetails(double newAmount, const std::string& newDescription) {
    amount = newAmount;
    description = newDescription;
}

std::string Expense::getExpenseDetails() const {
    return "ID: " + std::to_string(id) + ", Amount: " + std::to_string(amount) + ", Description: " + description;
}
double Expense::getAmount() const {
    return amount;
}
