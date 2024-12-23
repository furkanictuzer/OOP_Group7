#include "Expense.h"
#include "Category.h"

Expense::Expense(int id, double amount, const std::string& date, const std::string& description, Category* category)
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

int Expense::getId() const {
    return id;
}

std::string Expense::getDate() const
{
    return date;
}

Category* Expense::getCategory()
{
    return category;
}

std::string Expense::getDescription() const {
    return description;
}

bool Expense::operator==(const Expense& other) const {
    // Karşılaştırma mantığını belirleyin. Örneğin, ID'ye göre karşılaştırma:
    return this->id == other.id;
}
