#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <vector>
#include "Expense.h"
#include "Budget.h"

class NotificationManager {
private:
    std::vector<Expense> repeatedExpenses;
    std::vector<Budget> budgets;

public:
    std::vector<Expense> getExpensesToNotify();
    std::vector<Budget> getBudgetsToNotify();
    void checkBudgets();
    void checkExpenses();
    void notify();
};

#endif // NOTIFICATIONMANAGER_H
