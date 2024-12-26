#include "NotificationManager.h"

std::vector<RepeatedExpense> NotificationManager::repeatedExpenses;
std::vector<Budget> NotificationManager::budgets;

std::vector<RepeatedExpense> NotificationManager::getExpensesToNotify() {
    return repeatedExpenses;
}

void NotificationManager::addExpense(const RepeatedExpense& newExpense) {
    repeatedExpenses.push_back(newExpense);
}

std::vector<Budget> NotificationManager::getBudgetsToNotify() {
    return budgets;
}

void NotificationManager::addBudget(const Budget& newBudget) {
    budgets.push_back(newBudget);
}

void NotificationManager::checkBudgets() 
{

    for(Budget budget: budgets)
    {
        if(budget.getSpentAmount() >= budget.getBudgetAmount() * 0.9)
        {
            string message = "Budget " + budget.getName() + " is near exceeding! There is " 
                    + to_string(budget.getSpentAmount() - budget.getBudgetAmount()) + " left!\n";
            notify(message);
        }
    }
    
}

void NotificationManager::checkExpenses() 
{
    for(RepeatedExpense expense: repeatedExpenses)
    {
        if(expense.calculateNextOccurrence() <= MockClock::getCurrentTime() + std::chrono::hours(24))
        {
            string message = "The last pay date of " + expense.getExpenseDetails() + " is tomorrow. Do not forget to pay!\n";
            notify(message);
        }
    }
}

void NotificationManager::notify(const std::string& message) {
    fl_alert(message.c_str());
}

bool NotificationManager::hasNotificationForDate(const std::chrono::system_clock::time_point& date) {
    // Implementation for checking if there is a notification for the given date
}

void NotificationManager::triggerNotification(const std::chrono::system_clock::time_point& date) {
    // Implementation for triggering a notification for the given date
}
