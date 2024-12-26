#include "UiAddExpenseWindow.h"
#include "RepeatedExpense.h"
#include <FL/fl_ask.H>
#include <iostream>
#include "DateUtils.h"
#include "ExpenseManager.h"
#include "FileManager.h"
#include <iomanip> // Include for std::setw and std::setfill

UiAddExpenseWindow::UiAddExpenseWindow(int width, int height)
    : Fl_Window(width, height, "Add Expense") {
    amount_input = new Fl_Input(120, 20, 260, 30, "Amount:");
    category_choice = new Fl_Choice(120, 60, 260, 30, "Category:");
    day_choice = new Fl_Choice(120, 100, 60, 30, "Day:");
    month_choice = new Fl_Choice(230, 100, 60, 30, "Month:");
    year_choice = new Fl_Choice(330, 100, 60, 30, "Year:");
    description_input = new Fl_Multiline_Input(120, 140, 260, 60, "Description:");
    repeated_expense_check = new Fl_Check_Button(120, 210, 260, 30, "Is this a repeated expense?");
    repeat_count_input = new Fl_Input(120, 250, 260, 30, "Repeat Count:"); // New input field for repeat count
    repeat_count_input->hide(); // Initially hidden

    save_button = new Fl_Button(120, 290, 120, 30, "Save");
    cancel_button = new Fl_Button(260, 290, 120, 30, "Cancel");

    save_button->callback(save_callback, (void*)this);
    cancel_button->callback(cancel_callback, (void*)this);
    repeated_expense_check->callback(repeated_expense_check_callback, (void*)this); // Set callback for checkbox

    User& user = FileManager::getMainUser();
    std::vector<Category> categories = user.getCategories();

    for (const auto& category : categories) {
        category_choice->add(category.getCategoryName().c_str());
    }

    populateDateChoices();

    end();
}

UiAddExpenseWindow::~UiAddExpenseWindow() {
    delete amount_input;
    delete category_choice;
    delete day_choice;
    delete month_choice;
    delete year_choice;
    delete description_input;
    delete repeated_expense_check;
    delete repeat_count_input; // Delete the new input field
    delete save_button;
    delete cancel_button;
}

void UiAddExpenseWindow::populateDateChoices() {
    for (int i = 1; i <= 31; ++i) {
        day_choice->add(std::to_string(i).c_str());
    }

    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (const char* month : months) {
        month_choice->add(month);
    }

    for (int i = 2020; i <= 2030; ++i) {
        year_choice->add(std::to_string(i).c_str());
    }
}

void UiAddExpenseWindow::repeated_expense_check_callback(Fl_Widget* widget, void* data) {
    UiAddExpenseWindow* window = (UiAddExpenseWindow*)data;
    if (window->repeated_expense_check->value()) {
        window->repeat_count_input->show();
    } else {
        window->repeat_count_input->hide();
    }
    window->redraw();
}

void UiAddExpenseWindow::save_callback(Fl_Widget* widget, void* data) {
    UiAddExpenseWindow* window = (UiAddExpenseWindow*)data;
    std::string amount = window->amount_input->value();
    std::string category = window->category_choice->text();
    std::string day = window->day_choice->text();
    std::string month = window->month_choice->text();
    std::string year = window->year_choice->text();
    std::string description = window->description_input->value();
    bool is_repeated = window->repeated_expense_check->value();
    std::string repeat_count;

    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Day: " << day << std::endl;
    std::cout << "Month: " << month << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Is Repeated: " << is_repeated << std::endl;

    if (amount.empty()) {
        fl_alert("Amount must be filled out.");
        return;
    }
    if (category.empty()) {
        fl_alert("Category must be selected.");
        return;
    }
    if (day.empty()) {
        fl_alert("Day must be selected.");
        return;
    }
    if (month.empty()) {
        fl_alert("Month must be selected.");
        return;
    }
    if (year.empty()) {
        fl_alert("Year must be selected.");
        return;
    }
    if (description.empty()) {
        fl_alert("Description must be filled out.");
        return;
    }
    if (is_repeated) {
        repeat_count = window->repeat_count_input->value();
        if (repeat_count.empty()) {
            fl_alert("Repeat count must be filled out.");
            return;
        }
    }

    // Ensure the date string is in the format YYYY-MM-DD HH:MM:SS
    std::ostringstream dateStream;
    dateStream << year << "-"
               << std::setw(2) << std::setfill('0') << (window->month_choice->value() + 1) << "-"
               << std::setw(2) << std::setfill('0') << std::stoi(day) << " 14:30:00";
    std::string date = dateStream.str();
    std::cout << "Date: " << date << std::endl;

    User& user = FileManager::getMainUser();
    std::cout << "User: " << user.getUserName() << std::endl;
    Category* category_ptr = user.getCategoryByName(category);

    if (!category_ptr) {
        fl_alert("Invalid category.");
        return;
    }

    try {
        if (is_repeated) {
            int repeat_count_int = std::stoi(repeat_count);
            cout<< "Repeat count converted to int: " << repeat_count_int << endl;
            std::chrono::hours repeat_interval(30 * 24); // Example interval in hours (30 days)
            RepeatedExpense expense(user.getExpenseCount() + 1, std::stod(amount), DateUtils::stringToTimePoint(date), description, category_ptr, repeat_count_int, repeat_interval);
            
            cout<< "Expense created" << endl;
            ExpenseManager::addExpense(expense);
            cout<< "Expense added" << endl;
            NotificationManager::addExpense(expense);
            std::cout << "Repeated expense added." << std::endl;
        } else {
            Expense expense(user.getExpenseCount() + 1, std::stod(amount), DateUtils::stringToTimePoint(date), description, category_ptr);
            ExpenseManager::addExpense(expense);
            std::cout << "Expense added." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error saving expense: " << e.what() << std::endl;
        fl_alert("Failed to save expense. Please check the input values.");
        return;
    }

    std::cout << "Expense saved: " << amount << ", " << category << ", " << date << ", " << description << ", Repeated: " << is_repeated << std::endl;
    fl_message("Expense saved successfully.");

    window->hide();

    UiExpenseWindow* expense_window = new UiExpenseWindow(window->w(), window->h());
    expense_window->show();
}

void UiAddExpenseWindow::cancel_callback(Fl_Widget* widget, void* data) 
{
    UiAddExpenseWindow* window = (UiAddExpenseWindow*)data;
    window->hide();

    UiExpenseWindow* expense_window = new UiExpenseWindow(window->w(), window->h());
    expense_window->show();
}