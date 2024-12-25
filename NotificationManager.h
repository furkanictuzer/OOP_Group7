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
    std::vector<RepeatedExpense> repeatedExpenses;
    std::vector<Budget> budgets;
    MockClock mockClock;

public:
    NotificationManager(MockClock mc);
    std::vector<RepeatedExpense> getExpensesToNotify();
    void addExpense(RepeatedExpense newExpense);
    std::vector<Budget> getBudgetsToNotify();
    void addBudget(Budget newBudget);
    void checkBudgets();
    void checkExpenses();
    void notify(string message);
};

#endif // NOTIFICATIONMANAGER_H
