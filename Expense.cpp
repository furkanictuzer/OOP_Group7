#include "Expense.h"
#include "Category.h"
#include "DateUtils.h"
#include <sstream>
#include <iomanip>

/**
 * @brief Constructs an Expense object with the given details.
 * 
 * @param id The unique identifier of the expense.
 * @param amount The monetary amount of the expense.
 * @param date The date of the expense.
 * @param description A description of the expense.
 * @param category The category to which the expense belongs.
 */
Expense::Expense(int id, double amount, const std::chrono::system_clock::time_point& date, const std::string& description, Category* category)
    : id(id), amount(amount), date(date), description(description), category(category) {}

/**
 * @brief Default destructor for the Expense class.
 */
Expense::~Expense() {}

/**
 * @brief Updates the details of the expense.
 * 
 * @param newAmount The new monetary amount for the expense.
 * @param newDescription The new description for the expense.
 */
void Expense::setExpenseDetails(double newAmount, const std::string& newDescription) {
    amount = newAmount;
    description = newDescription;
}

/**
 * @brief Retrieves the details of the expense as a formatted string.
 * 
 * @return A string containing the expense ID, amount, and description.
 */
std::string Expense::getExpenseDetails() const {
    return "ID: " + std::to_string(id) + ", Amount: " + std::to_string(amount) + ", Description: " + description;
}

/**
 * @brief Gets the monetary amount of the expense.
 * 
 * @return The monetary amount.
 */
double Expense::getAmount() const {
    return amount;
}

/**
 * @brief Gets the unique identifier of the expense.
 * 
 * @return The expense ID.
 */
int Expense::getId() const {
    return id;
}

/**
 * @brief Gets the date of the expense.
 * 
 * @return The date as a std::chrono::system_clock::time_point.
 */
std::chrono::system_clock::time_point Expense::getDate() const {
    return date;
}

/**
 * @brief Gets the category associated with the expense.
 * 
 * @return A pointer to the Category object.
 */
Category* Expense::getCategory() const {
    return category;
}

/**
 * @brief Gets the description of the expense.
 * 
 * @return The description as a string.
 */
std::string Expense::getDescription() const {
    return description;
}

/**
 * @brief Compares two Expense objects for equality based on their IDs.
 * 
 * @param other The other Expense object to compare with.
 * @return True if the IDs are the same, false otherwise.
 */
bool Expense::operator==(const Expense& other) const {
    return id == other.id;
}
