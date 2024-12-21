#include "RepeatedExpense.h"

RepeatedExpense::RepeatedExpense(int id, double amount, const std::string& date, const std::string& description, Category* category, int num)
    : Expense(id, amount, date, description, category), numberOfRepetition(num) {}

std::string RepeatedExpense::calculateNextOccurrence() const {
    return "Next occurrence after " + repeatInterval;
}
