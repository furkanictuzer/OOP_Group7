#include <iostream>
#include <string>
#include <vector>

#include "User.h"
#include <iostream>

User::User(int id, const std::string& name, const std::string& pass, double bal)
    : user_id(id), username(name), password(pass), balance(bal) {}

std::string User::userInfo() const {
    return "User ID: " + std::to_string(user_id) +
           ", Username: " + username +
           ", Balance: " + std::to_string(balance);
}

void User::addCategory(const Category& category) {
    categories.push_back(category);
}

void User::removeCategory(const Category& category) {
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        if (it->getCategoryName() == category.getCategoryName()) {
            categories.erase(it);
            break;
        }
    }
}

double User::getBalance() const {
    return balance;
}

void User::updateUserInfo(const std::string& new_username, const std::string& new_password) {
    username = new_username;
    password = new_password;
}

bool User::deleteAccount() {
    //TODO
    std::cout << "Account deleted.\n";
    return true;
}

int User::getUserId() const {
    return user_id;
}

vector<Category> User::getCategories() const
{
    return categories;
}
