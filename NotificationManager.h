#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>

#include <FL/Fl.H>
#include <FL/fl_ask.H>

#include "MockClock.h"
#include "RepeatedExpense.h"
#include "Budget.h"

/**
 * @class NotificationManager
 * @brief A class to manage and trigger notifications for expenses and budgets.
 * 
 * This class handles storing and checking repeated expenses and budgets, and triggers
 * notifications when a condition is met (e.g., when a budget limit is reached or an expense
 * needs to be repeated). It provides methods to add expenses and budgets to track, as well as
 * to check and trigger notifications.
 */
class NotificationManager {
private:
    /** A list of repeated expenses to notify the user about. */
    static std::vector<RepeatedExpense> repeatedExpenses;

    /** A list of budgets to notify the user about. */
    static std::vector<Budget> budgets;

public:
    /**
     * @brief Get the list of expenses that require notifications.
     * 
     * This function returns a list of repeated expenses that have conditions met for
     * sending notifications.
     * 
     * @return A vector containing repeated expenses that need notifications.
     */
    static std::vector<RepeatedExpense> getExpensesToNotify();

    /**
     * @brief Add a new repeated expense to the notification manager.
     * 
     * This function adds a new repeated expense to the list of expenses being tracked for notifications.
     * 
     * @param newExpense The repeated expense to be added.
     */
    static void addExpense(const RepeatedExpense& newExpense);

    /**
     * @brief Get the list of budgets that require notifications.
     * 
     * This function returns a list of budgets that need notifications (e.g., when nearing the limit).
     * 
     * @return A vector containing budgets that need notifications.
     */
    static std::vector<Budget> getBudgetsToNotify();

    /**
     * @brief Add a new budget to the notification manager.
     * 
     * This function adds a new budget to the list of budgets being tracked for notifications.
     * 
     * @param newBudget The budget to be added.
     */
    static void addBudget(const Budget& newBudget);

    /**
     * @brief Check all budgets for notification conditions.
     * 
     * This function checks all budgets to determine if any conditions are met for sending notifications,
     * such as exceeding a predefined spending limit.
     */
    static void checkBudgets();

    /**
     * @brief Check all expenses for notification conditions.
     * 
     * This function checks all repeated expenses to determine if any conditions are met for sending notifications,
     * such as due dates or repeat frequencies.
     */
    static void checkExpenses();

    /**
     * @brief Trigger a notification with a custom message.
     * 
     * This function shows a notification message to the user.
     * 
     * @param message The message to be displayed in the notification.
     */
    static void notify(const std::string& message);

    /**
     * @brief Check if there is a notification for a specific date.
     * 
     * This function checks if a notification should be triggered for a given date.
     * 
     * @param date The date to check for a notification.
     * @return True if there is a notification for the specified date, false otherwise.
     */
    static bool hasNotificationForDate(const std::chrono::system_clock::time_point& date);

    /**
     * @brief Trigger a notification based on a specific date.
     * 
     * This function triggers a notification if there are any conditions for the specified date.
     * 
     * @param date The date to trigger a notification for.
     */
    static void triggerNotification(const std::chrono::system_clock::time_point& date);
};

#endif // NOTIFICATIONMANAGER_H
