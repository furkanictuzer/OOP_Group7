#include "UiMainWindow.h"
#include <iostream>

UiMainWindow::UiMainWindow(int width, int height)
    : Fl_Window(width, height, ("Main Window - " + FileManager::getMainUser().getUserName()).c_str()) {
    expenses_button = new Fl_Button(50, 50, 200, 40, "Expenses");
    set_budget_button = new Fl_Button(50, 100, 200, 40, "Set Budget");
    my_categories_button = new Fl_Button(50, 150, 200, 40, "My Categories");
    get_report_button = new Fl_Button(50, 200, 200, 40, "Get Report");
    recent_payments_button = new Fl_Button(50, 250, 200, 40, "Recently Completed Payments");

    expenses_button->callback(button_callback, (void*)this);
    set_budget_button->callback(button_callback, (void*)this);
    my_categories_button->callback(button_callback, (void*)this);
    get_report_button->callback(button_callback, (void*)this);
    recent_payments_button->callback(button_callback, (void*)this);
    end();
}

void UiMainWindow::button_callback(Fl_Widget* widget, void* data) {
    UiMainWindow* window = (UiMainWindow*)data;
    if (widget == window->expenses_button) {
        std::cout << "Expenses button clicked" << std::endl;
        window->navigateToExpense();
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
    }
}

void UiMainWindow::navigateToExpense() {
    this->hide();

    UiExpenseWindow* expense_window = new UiExpenseWindow(this->w(), this->h());
    expense_window->show();
}

void UiMainWindow::navigateToBudget() {
    this->hide();

    UiBudgetWindow* budget_window = new UiBudgetWindow(this->w(), this->h());
    budget_window->show();
}

void UiMainWindow::navigateToCategories() {
    this->hide();

    UiCategoryWindow* category_window = new UiCategoryWindow(this->w(), this->h());
    category_window->show();
}

void UiMainWindow::navigateToReport() {
    fl_message("Navigating to Get Report...");
}

void UiMainWindow::navigateToPayments() {
    fl_message("Navigating to Recently Completed Payments...");
}
