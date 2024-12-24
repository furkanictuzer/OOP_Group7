#include "UiMainWindow.h"
#include <iostream>

UiMainWindow::UiMainWindow(int width, int height, const std::string& name)
    : Fl_Window(width, height, ("Main Window - " + name).c_str()) {
    last_expenses_button = new Fl_Button(50, 50, 200, 40, "Last Expenses");
    set_budget_button = new Fl_Button(50, 100, 200, 40, "Set Budget");
    my_categories_button = new Fl_Button(50, 150, 200, 40, "My Categories");
    get_report_button = new Fl_Button(50, 200, 200, 40, "Get Report");
    recent_payments_button = new Fl_Button(50, 250, 200, 40, "Recently Completed Payments");
    add_expense_button = new Fl_Button(50, 300, 200, 40, "Add Expense");

    last_expenses_button->callback(button_callback, (void*)this);
    set_budget_button->callback(button_callback, (void*)this);
    my_categories_button->callback(button_callback, (void*)this);
    get_report_button->callback(button_callback, (void*)this);
    recent_payments_button->callback(button_callback, (void*)this);
    add_expense_button->callback(button_callback, (void*)this);

    end();
}

void UiMainWindow::button_callback(Fl_Widget* widget, void* data) {
    UiMainWindow* window = (UiMainWindow*)data;
    if (widget == window->last_expenses_button) {
        std::cout << "Last Expenses button clicked" << std::endl;
        window->navigateToLastExpense();
    } else if (widget == window->set_budget_button) {
        std::cout << "Set Budget button clicked" << std::endl;
        window->navigateToBudget();
    } else if (widget == window->my_categories_button) {
        std::cout << "My Categories button clicked" << std::endl;
        window->navigateToCategories();
    } else if (widget == window->get_report_button) {
        std::cout << "Get Report button clicked" << std::endl;
        window->navigateToReport();
    } else if (widget == window->recent_payments_button) {
        std::cout << "Recently Completed Payments button clicked" << std::endl;
        window->navigateToPayments();
    } else if (widget == window->add_expense_button) {
        std::cout << "Add Expense button clicked" << std::endl;
        window->navigateToAddExpense();
    }
}

void UiMainWindow::navigateToLastExpense() {
    fl_message("Navigating to Last Expenses...");
}

void UiMainWindow::navigateToBudget() {
    fl_message("Navigating to Set Budget...");
}

void UiMainWindow::navigateToCategories() {
    fl_message("Navigating to My Categories...");
}

void UiMainWindow::navigateToReport() {
    fl_message("Navigating to Get Report...");
}

void UiMainWindow::navigateToPayments() {
    fl_message("Navigating to Recently Completed Payments...");
}

void UiMainWindow::navigateToAddExpense() {
    fl_message("Navigating to Add Expense...");
}
