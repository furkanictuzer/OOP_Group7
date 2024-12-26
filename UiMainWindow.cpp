#include "UiMainWindow.h"
#include "NotificationManager.h"
#include "MockClock.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>

/**
 * @class UiMainWindow
 * @brief The main window for the application after login.
 * 
 * This class represents the main window that allows the user to navigate between different sections 
 * of the application such as expenses, budget, categories, reports, and profile.
 */
UiMainWindow::UiMainWindow(int width, int height)
    : Fl_Window(width, height, ("Main Window - " + FileManager::getMainUser().getUserName()).c_str()) {
    
    // Create buttons for different sections
    expenses_button = new Fl_Button(50, 50, 200, 40, "Expenses");
    set_budget_button = new Fl_Button(50, 100, 200, 40, "Set Budget");
    my_categories_button = new Fl_Button(50, 150, 200, 40, "My Categories");
    get_report_button = new Fl_Button(50, 200, 200, 40, "Get Report");
    profile_button = new Fl_Button(300, 50, 100, 40, "Profile");

    // Set callback functions for buttons
    expenses_button->callback(button_callback, (void*)this);
    set_budget_button->callback(button_callback, (void*)this);
    my_categories_button->callback(button_callback, (void*)this);
    get_report_button->callback(button_callback, (void*)this);
    profile_button->callback(button_callback, (void*)this);

    // Display the current date
    date_display = new Fl_Box(50, 300, 300, 40, "Date: --");
    date_display->box(FL_UP_BOX);
    date_display->labelsize(14);
    date_display->labelfont(FL_BOLD + FL_ITALIC);
    date_display->labeltype(FL_SHADOW_LABEL);
    

    // Finalize window setup
    end();
}

/**
 * @brief Destructor for UiMainWindow.
 * 
 * This destructor cleans up the resources allocated for the main window.
 */
UiMainWindow::~UiMainWindow() {
    delete expenses_button;
    delete set_budget_button;
    delete my_categories_button;
    delete get_report_button;
    delete profile_button;
    delete date_display;
}

/**
 * @brief Callback function for all buttons in the main window.
 * 
 * This function handles the button clicks for navigation. Depending on which button is clicked, 
 * it will navigate to the corresponding window (e.g., Expense, Budget, etc.).
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiMainWindow::button_callback(Fl_Widget* widget, void* data) {
    UiMainWindow* window = (UiMainWindow*)data;
    
    // Check which button was clicked and navigate accordingly
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
    } else if (widget == window->profile_button) {
        std::cout << "Profile button clicked" << std::endl;
        window->navigateToProfile();
    }
}

/**
 * @brief Navigate to the expense window.
 * 
 * This function hides the main window and creates and shows the UiExpenseWindow.
 */
void UiMainWindow::navigateToExpense() {
    this->hide();
    UiExpenseWindow* expense_window = new UiExpenseWindow(this->w(), this->h());
    expense_window->show();
}

/**
 * @brief Navigate to the budget window.
 * 
 * This function hides the main window and creates and shows the UiBudgetWindow.
 */
void UiMainWindow::navigateToBudget() {
    this->hide();
    UiBudgetWindow* budget_window = new UiBudgetWindow(this->w(), this->h());
    budget_window->show();
}

/**
 * @brief Navigate to the categories window.
 * 
 * This function hides the main window and creates and shows the UiCategoryWindow.
 */
void UiMainWindow::navigateToCategories() {
    this->hide();
    UiCategoryWindow* category_window = new UiCategoryWindow(this->w(), this->h());
    category_window->show();
}

/**
 * @brief Navigate to the reports window.
 * 
 * This function hides the main window and creates and shows the UiReportsWindow.
 */
void UiMainWindow::navigateToReport() {
    this->hide();
    UiReportsWindow* reports_window = new UiReportsWindow(this->w(), this->h());
    reports_window->show();
}

/**
 * @brief Navigate to the profile window.
 * 
 * This function hides the main window and creates and shows the UiProfileWindow.
 */
void UiMainWindow::navigateToProfile() {
    this->hide();
    UiProfileWindow* profile_window = new UiProfileWindow(this->w(), this->h());
    profile_window->show();
}
