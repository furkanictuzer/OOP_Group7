#include "Expense.h"
#include "Category.h"
#include "DateUtils.h"
#include <sstream>
#include <iomanip>

Expense::Expense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category)
    : id(id), amount(amount), date(date), description(description), category(category) {}

Expense::~Expense() {}

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

int Expense::getId() const {
    return id;
}

std::chrono::system_clock::time_point Expense::getDate() const {
    return date;
}

Category* Expense::getCategory() const {
    return category;
}

std::string Expense::getDescription() const {
    return description;
}

bool Expense::operator==(const Expense& other) const {
    return id == other.id;
}
