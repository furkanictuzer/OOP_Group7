#include "UiExpenseWindow.h"
#include <iostream>

UiExpenseWindow::UiExpenseWindow(int height, int width, std::string name)
        : Fl_Window(width, height, "New Expense")
{
    expenseAmount = new Fl_Input(100, 50, 100, 40, "Expense Amount: ");
    categoryChoice = new Fl_Choice(100, 120, 100, 40, "Choose Category: ");
    for(Category category : User::getCategories())
    {
        categoryChoice->add(category.getCategoryName());
    }

    submitButton = new Fl_Button(250, 200, 60, 60, "Submit");
    end();
}


UiExpenseWindow::~UiExpenseWindow()
{
    delete expenseAmount;
    delete categoryChoice;
    delete submitButton;
}