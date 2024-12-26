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

class NotificationManager {
private:
    static std::vector<RepeatedExpense> repeatedExpenses;
    static std::vector<Budget> budgets;

public:
    static std::vector<RepeatedExpense> getExpensesToNotify();
    static void addExpense(const RepeatedExpense& newExpense);
    static std::vector<Budget> getBudgetsToNotify();
    static void addBudget(const Budget& newBudget);
    static void checkBudgets();
    static void checkExpenses();
    static void notify(const std::string& message);
    static bool hasNotificationForDate(const std::chrono::system_clock::time_point& date);
    static void triggerNotification(const std::chrono::system_clock::time_point& date);
};

#endif // NOTIFICATIONMANAGER_H
