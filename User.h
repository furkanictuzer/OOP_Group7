#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Category.h"
#include "Budget.h"

/**
 * @class User
 * @brief Represents a user of the application with associated data like username, password, categories, and budgets.
 * 
 * The User class is responsible for storing and managing user information, including their username, password,
 * categories, budgets, and balance. It also provides functions to update user information, add or remove categories,
 * and handle the user's finances.
 */
class User {
private:
    int user_id; ///< The unique ID of the user.
    std::string username; ///< The username of the user.
    std::string password; ///< The password of the user.
    std::vector<Category> categories; ///< The list of categories associated with the user.
    std::vector<Budget> budgets; ///< The list of budgets set by the user.
    double balance; ///< The balance of the user.

public:
    /**
     * @brief Constructs a User object with the given parameters.
     * 
     * Initializes the user with a unique ID, username, password, and balance.
     * 
     * @param id The unique ID for the user.
     * @param name The username of the user.
     * @param pass The password of the user.
     * @param bal The initial balance of the user.
     */
    User(int id, const std::string& name, const std::string& pass, double bal);

    /**
     * @brief Retrieves the user information as a string.
     * 
     * This function returns a formatted string containing the user's username and balance.
     * 
     * @return A string representing the user's information.
     */
    std::string userInfo() const;

    /**
     * @brief Retrieves the username of the user.
     * 
     * @return The username of the user.
     */
    std::string getUserName() const;

    /**
     * @brief Sets a new username for the user.
     * 
     * This function updates the user's username with the provided new username.
     * 
     * @param new_username The new username to be set for the user.
     */
    void setUsername(const std::string& new_username);

    /**
     * @brief Retrieves the password of the user.
     * 
     * @return The password of the user.
     */
    std::string getPassword() const;

    /**
     * @brief Sets a new password for the user.
     * 
     * This function updates the user's password with the provided new password.
     * 
     * @param new_password The new password to be set for the user.
     */
    void setPassword(const std::string& new_password);

    /**
     * @brief Adds a category to the user's list of categories.
     * 
     * This function adds a new category to the user's list of categories.
     * 
     * @param category The category to be added.
     */
    void addCategory(const Category& category);

    /**
     * @brief Removes a category from the user's list of categories.
     * 
     * This function removes a category from the user's list of categories.
     * 
     * @param category The category to be removed.
     */
    void removeCategory(const Category& category);

    /**
     * @brief Retrieves the current balance of the user.
     * 
     * @return The current balance of the user.
     */
    double getBalance() const;

    /**
     * @brief Adds a budget to the user's list of budgets.
     * 
     * This function adds a new budget to the user's list of budgets.
     * 
     * @param budget The budget to be added.
     */
    void addBudget(const Budget& budget);
    Budget getCurrentBudget();
    void updateUserInfo(const std::string& new_username, const std::string& new_password);

    /**
     * @brief Deletes the user's account.
     * 
     * This function deletes the user's account and returns whether the deletion was successful.
     * 
     * @return True if the account was successfully deleted, otherwise false.
     */
    bool deleteAccount();

    /**
     * @brief Retrieves the unique ID of the user.
     * 
     * @return The unique ID of the user.
     */
    int getUserId() const;

    /**
     * @brief Retrieves the list of categories associated with the user.
     * 
     * @return A vector of categories associated with the user.
     */
    std::vector<Category> getCategories() const;

    /**
     * @brief Retrieves a category by its name.
     * 
     * This function searches for a category by its name and returns a pointer to the category if found.
     * 
     * @param name The name of the category to search for.
     * @return A pointer to the category if found, otherwise nullptr.
     */
    Category* getCategoryByName(const std::string& name);

    /**
     * @brief Retrieves the number of expenses in the user's categories.
     * 
     * This function returns the total number of expenses across all categories for the user.
     * 
     * @return The number of expenses for the user.
     */
    int getExpenseCount() const;
};

#endif // USER_H
