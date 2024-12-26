#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <vector>

// Forward declaration
class Expense;

/**
 * @class Category
 * @brief Represents a category that holds a collection of expenses.
 */
class Category {
private:
    std::string name; ///< The name of the category.
    std::vector<Expense*> expenses; ///< The list of expenses in this category.

public:
    /**
     * @brief Constructor that initializes a category with a given name.
     * 
     * @param name The name of the category.
     */
    Category(const std::string& name);

    /**
     * @brief Adds an expense to the category.
     * 
     * This function adds a given expense to the category's list of expenses.
     * 
     * @param expense The expense to add to the category.
     */
    void addExpense(Expense* expense);

    /**
     * @brief Removes an expense from the category.
     * 
     * This function removes a given expense from the category's list of expenses.
     * 
     * @param expense The expense to remove from the category.
     */
    void removeExpense(Expense* expense);

    /**
     * @brief Gets the name of the category.
     * @return The name of the category.
     */
    std::string getCategoryName() const;

    /**
     * @brief Gets the list of expenses in this category.
     * @return A constant reference to the list of expenses.
     */
    const std::vector<Expense*>& getExpenses() const;

    /**
     * @brief Sets the name of the category.
     * 
     * @param name The new name for the category.
     */
    void setCategoryName(const std::string& name);

    /**
     * @brief Gets the total number of expenses in this category.
     * @return The number of expenses in the category.
     */
    int getExpenseCount() const;

    /**
     * @brief Overloads the '<' operator to enable comparison between Category objects.
     * 
     * This function compares two categories based on their names.
     * 
     * @param other The other category to compare with.
     * @return true if this category's name is lexicographically smaller than the other category's name, false otherwise.
     */
    bool operator<(const Category& other) const {
        return this->name < other.name;
    }
};

#endif // CATEGORY_H
