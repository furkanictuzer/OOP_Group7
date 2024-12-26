#include "NotificationManager.h"

std::vector<RepeatedExpense> NotificationManager::repeatedExpenses;
std::vector<Budget> NotificationManager::budgets;

/**
 * @brief Retrieves a list of repeated expenses that require notifications.
 * 
 * This function returns all repeated expenses that are stored in the `repeatedExpenses` vector. 
 * These expenses are checked for upcoming payments, and notifications are generated if necessary.
 * 
 * @return A vector containing all repeated expenses that need to be notified.
 */
std::vector<RepeatedExpense> NotificationManager::getExpensesToNotify() {
    return repeatedExpenses;
}

/**
 * @brief Adds a new repeated expense to the notification list.
 * 
 * This function adds the given repeated expense to the `repeatedExpenses` vector. 
 * The new expense will later be checked for upcoming notifications.
 * 
 * @param newExpense The repeated expense to add to the notification list.
 */
void NotificationManager::addExpense(const RepeatedExpense& newExpense) {
    repeatedExpenses.push_back(newExpense);
}

/**
 * @brief Retrieves a list of budgets that require notifications.
 * 
 * This function returns all budgets stored in the `budgets` vector that are approaching their limits. 
 * Notifications are generated for budgets that are nearing their spending thresholds.
 * 
 * @return A vector containing all budgets that need to be notified.
 */
std::vector<Budget> NotificationManager::getBudgetsToNotify() {
    return budgets;
}

/**
 * @brief Adds a new budget to the notification list.
 * 
 * This function adds a new budget to the `budgets` vector. The budget will be monitored for
 * notifications about approaching the budget limit.
 * 
 * @param newBudget The budget to add to the notification list.
 */
void NotificationManager::addBudget(const Budget& newBudget) {
    budgets.push_back(newBudget);
}

/**
 * @brief Checks the budgets to determine if any are approaching their limit.
 * 
 * This function iterates over all stored budgets and checks if their spent amount is within 90% of the budgeted amount.
 * If so, a notification is triggered to alert the user about the approaching limit.
 */
void NotificationManager::checkBudgets() 
{
    for(Budget budget : budgets)
    {
        if(budget.getSpentAmount() >= budget.getBudgetAmount() * 0.9)
        {
            std::string message = "Budget " + budget.getName() + " is near exceeding! There is " 
                    + std::to_string(budget.getSpentAmount() - budget.getBudgetAmount()) + " left!\n";
            notify(message);
        }
    }
}

/**
 * @brief Checks the repeated expenses to determine if any are due soon.
 * 
 * This function iterates over all stored repeated expenses and checks if their next occurrence is within 24 hours.
 * If so, a notification is triggered to remind the user to pay the expense.
 */
void NotificationManager::checkExpenses() 
{
    for(RepeatedExpense expense : repeatedExpenses)
    {
        if(expense.calculateNextOccurrence() <= MockClock::getCurrentTime() + std::chrono::hours(24))
        {
            std::string message = "The last pay date of " + expense.getExpenseDetails() + " is tomorrow. Do not forget to pay!\n";
            notify(message);
        }
    }
}

/**
 * @brief Displays a notification message to the user.
 * 
 * This function uses the FLTK library's `fl_alert` function to display a message to the user. 
 * The message is typically related to an upcoming expense or a budget nearing its limit.
 * 
 * @param message The message to display in the notification.
 */
void NotificationManager::notify(const std::string& message) {
    fl_alert(message.c_str());
}

/**
 * @brief Checks if there is a notification scheduled for the given date.
 * 
 * This function is intended to check if any notifications are scheduled for the provided date.
 * The implementation is currently left as a placeholder.
 * 
 * @param date The date to check for scheduled notifications.
 * @return A boolean indicating whether a notification exists for the given date.
 */
bool NotificationManager::hasNotificationForDate(const std::chrono::system_clock::time_point& date) {
    // Implementation for checking if there is a notification for the given date
    return false; // Placeholder implementation
}

/**
 * @brief Triggers a notification for the given date.
 * 
 * This function is intended to trigger a notification for the provided date.
 * The implementation is currently left as a placeholder.
 * 
 * @param date The date for which to trigger a notification.
 */
void NotificationManager::triggerNotification(const std::chrono::system_clock::time_point& date) {
    // Implementation for triggering a notification for the given date
}
