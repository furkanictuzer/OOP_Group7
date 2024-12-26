#include "Category.h"
#include <algorithm>
#include "Expense.h"

/**
 * @brief Constructs a Category with a given name.
 * 
 * @param name The name of the category.
 */
Category::Category(const std::string &name) : name(name) {}

/**
 * @brief Adds an expense to the category.
 * 
 * @param expense A pointer to the Expense object to be added.
 */
void Category::addExpense(Expense *expense)
{
    expenses.push_back(expense);
}

/**
 * @brief Removes an expense from the category.
 * 
 * @param expense A pointer to the Expense object to be removed.
 */
void Category::removeExpense(Expense *expense)
{
    expenses.erase(std::remove(expenses.begin(), expenses.end(), expense), expenses.end());
}

/**
 * @brief Gets the name of the category.
 * 
 * @return The name of the category as a string.
 */
std::string Category::getCategoryName() const
{
    return name;
}

/**
 * @brief Sets a new name for the category.
 * 
 * @param newName The new name of the category.
 */
void Category::setCategoryName(const std::string &newName)
{
    this->name = newName;
}

/**
 * @brief Gets all the expenses associated with the category.
 * 
 * @return A constant reference to a vector of Expense pointers.
 */
const std::vector<Expense *> &Category::getExpenses() const
{
    return expenses;
}

/**
 * @brief Gets the total number of expenses in the category.
 * 
 * @return The number of expenses as an integer.
 */
int Category::getExpenseCount() const
{
    return expenses.size();
}
