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
    month_choice = new Fl_Choice(220, 100, 60, 30, "Month:");
    year_choice = new Fl_Choice(320, 100, 60, 30, "Year:");
    description_input = new Fl_Multiline_Input(120, 140, 260, 60, "Description:");
    repeated_expense_check = new Fl_Check_Button(120, 210, 260, 30, "Is this a repeated expense?");
    
    save_button = new Fl_Button(120, 250, 120, 30, "Save");
    cancel_button = new Fl_Button(260, 250, 120, 30, "Cancel");

    save_button->callback(save_callback, (void*)this);
    cancel_button->callback(cancel_callback, (void*)this);

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

void UiAddExpenseWindow::save_callback(Fl_Widget* widget, void* data) {
    UiAddExpenseWindow* window = (UiAddExpenseWindow*)data;
    std::string amount = window->amount_input->value();
    std::string category = window->category_choice->text();
    std::string day = window->day_choice->text();
    std::string month = window->month_choice->text();
    std::string year = window->year_choice->text();
    std::string description = window->description_input->value();
    bool is_repeated = window->repeated_expense_check->value();

    if (amount.empty() || category.empty() || day.empty() || month.empty() || year.empty() || description.empty()) {
        fl_alert("All fields must be filled out.");
        return;
    }

    // Ensure the date string is in the format YYYY-MM-DD HH:MM:SS
    std::ostringstream dateStream;
    dateStream << year << "-"
               << std::setw(2) << std::setfill('0') << (window->month_choice->value() + 1) << "-"
               << std::setw(2) << std::setfill('0') << std::stoi(day) << " 14:30:00";
    std::string date = dateStream.str();
    std::cout << "Date: " << date << std::endl;

    User& user = FileManager::getMainUser();
    Category* category_ptr = user.getCategoryByName(category);

    if (!category_ptr) {
        fl_alert("Invalid category.");
        return;
    }

    if (is_repeated) {
        int repeat_count = 12; // Example repeat count, you can modify this as needed
        std::chrono::hours repeat_interval(30 * 24); // Example interval in hours (30 days)
        RepeatedExpense expense(user.getExpenseCount() + 1, std::stod(amount), DateUtils::stringToTimePoint(date), description, category_ptr, repeat_count, repeat_interval);
        ExpenseManager::addExpense(expense);
    } else {
        try
        {
            Expense expense(user.getExpenseCount() + 1, std::stod(amount), DateUtils::stringToTimePoint(date), description, category_ptr);
            ExpenseManager::addExpense(expense);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }

    std::cout << "Expense saved: " << amount << ", " << category << ", " << date << ", " << description << ", Repeated: " << is_repeated << std::endl;
    fl_message("Expense saved successfully.");

    window->hide();
}

void UiAddExpenseWindow::cancel_callback(Fl_Widget* widget, void* data) 
{
    UiAddExpenseWindow* window = (UiAddExpenseWindow*)data;
    window->hide();
}