#include "UiBudgetWindow.h"

UiBudgetWindow::UiBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Budget Window")
{
    budgetBrowser = new Fl_Browser(20, 20, width - 40, height - 120);
    closeButton = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    newBudgetButton = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "New Budget");

    close_button->callback(close_callback, (void*)this);
    add_expense_button->callback(add_expense_callback, (void*)this);

    populateExpenses();

    end();
}

UiBudgetWindow::~UiBudgetWindow()
{
    delete budgetBrowser;
    delete closeButton;
    delete newBudgetButton;
}

void UiExpenseWindow::populateExpenses() {
    //If can be, a set button for at least last budget should be added
    //and populate function should be written
}

void UiBudgetWindow::close_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

void UiBudgetWindow::add_expense_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;

    //UiAddBudgetWindow class wil be written
    UiAddBudgetWindow* add_budget_window = new UiAddBudgetWindow(window->w(), window->h());
    add_budget_window->show();
}