#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include <fstream>

/**
 * @class User
 * @brief Represents a user in the system with their account details, budget, and categories.
 */
class User {
private:
    int user_id; ///< Unique ID of the user
    std::string username; ///< Username of the user
    std::string password; ///< Password for the user
    double balance; ///< Balance of the user
    std::vector<Category> categories; ///< List of categories associated with the user
    std::vector<Budget> budgets; ///< List of budgets associated with the user

public:
    /**
     * @brief Constructor to initialize a User object.
     * 
     * @param id The unique user ID.
     * @param name The username of the user.
     * @param pass The password of the user.
     * @param bal The initial balance of the user.
     */
    User(int id, const std::string& name, const std::string& pass, double bal);

    /**
     * @brief Gets the user information as a string.
     * 
     * @return A string containing the user ID, username, and balance.
     */
    std::string userInfo() const;

    /**
     * @brief Gets the username of the user.
     * 
     * @return The username of the user.
     */
    std::string getUserName() const;

    /**
     * @brief Sets a new username for the user.
     * 
     * @param new_username The new username to set.
     */
    void setUsername(const std::string& new_username);

    /**
     * @brief Gets the password of the user.
     * 
     * @return The password of the user.
     */
    std::string getPassword() const;

    /**
     * @brief Sets a new password for the user.
     * 
     * @param new_password The new password to set.
     */
    void setPassword(const std::string& new_password);

    /**
     * @brief Adds a new category to the user's categories.
     * 
     * @param category The category to add.
     */
    void addCategory(const Category& category);

    /**
     * @brief Removes a category from the user's categories.
     * 
     * @param category The category to remove.
     */
    void removeCategory(const Category& category);

    /**
     * @brief Gets the current balance of the user.
     * 
     * @return The balance of the user.
     */
    double getBalance() const;

    /**
     * @brief Adds a new budget to the user's budgets.
     * 
     * @param budget The budget to add.
     */
    void addBudget(const Budget& budget);

    /**
     * @brief Gets the most recent budget associated with the user.
     * 
     * @return The most recent budget.
     */
    Budget& getCurrentBudget();

    /**
     * @brief Gets all the budgets associated with the user.
     * 
     * @return A vector containing all budgets associated with the user.
     */
    std::vector<Budget> getBudgets() const;

    /**
     * @brief Updates the user's username and password.
     * 
     * @param new_username The new username to set.
     * @param new_password The new password to set.
     */
    void updateUserInfo(const std::string& new_username, const std::string& new_password);

    /**
     * @brief Deletes the user's account and removes their data from the system.
     * 
     * This function clears the user's categories and budgets and deletes their data from
     * the user data file.
     * 
     * @return True if the account was successfully deleted, otherwise false.
     */
    bool deleteAccount();

    /**
     * @brief Gets the user ID.
     * 
     * @return The user ID.
     */
    int getUserId() const;

    /**
     * @brief Gets all categories associated with the user.
     * 
     * @return A vector containing all categories associated with the user.
     */
    std::vector<Category> getCategories() const;

    /**
     * @brief Gets a category by its name.
     * 
     * @param name The name of the category.
     * @return A pointer to the category if found.
     * @throws std::invalid_argument if the category is not found.
     */
    Category* getCategoryByName(const std::string& name);

    /**
     * @brief Gets the total number of expenses across all categories.
     * 
     * @return The total number of expenses.
     */
    int getExpenseCount() const;

    /**
     * @brief Gets the total number of budgets associated with the user.
     * 
     * @return The total number of budgets.
     */
    int getBudgetCount() const;
};
