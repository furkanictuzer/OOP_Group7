#include "NotificationManager.h"

NotificationManager::NotificationManager(MockClock mc)
{
    this->mockClock = mc;
}

std::vector<RepeatedExpense> NotificationManager::getExpensesToNotify() {
    return repeatedExpenses;
}

void NotificationManager::addExpense(RepeatedExpense newExpense)
{
    this->repeatedExpenses.push_back(newExpense);
}

std::vector<Budget> NotificationManager::getBudgetsToNotify() {
    return budgets;
}

void NotificationManager::addBudget(Budget newBudget)
{
    this->budgets.push_back(newBudget);
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
        if(expense.calculateNextOccurrence() <= mockClock.getCurrentTime() + std::chrono::hours(24))
        {
            string message = "The last pay date of " + expense.getExpenseDetails() + " is tomorrow. Do not forget to pay!\n";
            notify(message);
        }
    }
}

void NotificationManager::notify(string message) 
{
    Fl::visual(Fl::DOUBLE);
    fltk_message("Expense Tracker App", message);
}
