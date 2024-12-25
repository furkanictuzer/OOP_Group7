#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Category.h"
#include "Budget.h"

class User {
private:
    int user_id;
    std::string username;
    std::string password;
    std::vector<Category> categories;
    std::vector<Budget> budgets;
    double balance;

public:
    User(int id, const std::string& name, const std::string& pass, double bal);

    std::string userInfo() const;
    std::string getUserName() const;
    std::string getPassword() const;
    void addCategory(const Category& category);
    void removeCategory(const Category& category);
    double getBalance() const;
    Budget getCurrentBudget();
    void updateUserInfo(const std::string& new_username, const std::string& new_password);
    bool deleteAccount();
    int getUserId() const;
    vector<Category> getCategories() const;
    Category* getCategoryByName(const std::string& name);
    int getExpenseCount() const;
};

#endif // USER_H