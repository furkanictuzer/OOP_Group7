/**
 * @brief Implementation of the UI for adding a budget.
 */

#include "UiAddBudgetWindow.h"
#include "DateUtils.h"
#include "FileManager.h"
#include <FL/fl_ask.H>
#include <iomanip>
#include <iostream>

/**
 * @brief Constructor for the UiAddBudgetWindow class.
 * 
 * Initializes the UI elements and sets up the layout.
 * Also populates date selection choices.
 * 
 * @param width Width of the window.
 * @param height Height of the window.
 */
UiAddBudgetWindow::UiAddBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Add Budget Window") 
{
    nameInput = new Fl_Input(120, 20, 200, 30, "Name: ");
    dayChoiceStart = new Fl_Choice(120, 60, 60, 30, "Starting Day:");
    monthChoiceStart = new Fl_Choice(320, 60, 60, 30, "Starting Month:");
    yearChoiceStart = new Fl_Choice(520, 60, 60, 30, "Starting Year:");

    dayChoiceEnd = new Fl_Choice(120, 100, 60, 30, "Ending Day: ");
    monthChoiceEnd = new Fl_Choice(320, 100, 60, 30, "Ending Month: ");
    yearChoiceEnd = new Fl_Choice(520, 100, 60, 30, "Ending Year: ");

    amountInput = new Fl_Input(120, 140, 200, 30, "Amount: ");
    sourceInput = new Fl_Input(120, 180, 200, 30, "Source: ");

    addButton = new Fl_Button(120, 210, 90, 30, "Add");
    cancelButton = new Fl_Button(220, 210, 90, 30, "Cancel");

    addButton->callback(add_callback, (void*)this);
    cancelButton->callback(cancel_callback, (void*)this);

    populateDateChoices();

    end();
}

/**
 * @brief Destructor for the UiAddBudgetWindow class.
 * 
 * Cleans up the allocated resources for all UI elements.
 */
UiAddBudgetWindow::~UiAddBudgetWindow()
{
    delete nameInput;
    delete dayChoiceStart;
    delete dayChoiceEnd;
    delete monthChoiceStart;
    delete monthChoiceEnd;
    delete yearChoiceStart;
    delete yearChoiceEnd;
    delete amountInput;
    delete cancelButton;
}

/**
 * @brief Populates the date choice dropdowns with day, month, and year values.
 */
void UiAddBudgetWindow::populateDateChoices() {
    for (int i = 1; i <= 31; ++i) {
        dayChoiceStart->add(std::to_string(i).c_str());
    }
    for (int i = 1; i <= 31; ++i) {
        dayChoiceEnd->add(std::to_string(i).c_str());
    }

    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (const char* month : months) {
        monthChoiceStart->add(month);
    }
    for (const char* month : months) {
        monthChoiceEnd->add(month);
    }

    for (int i = 2020; i <= 2030; ++i) {
        yearChoiceStart->add(std::to_string(i).c_str());
    }
    for (int i = 2020; i <= 2030; ++i) {
        yearChoiceEnd->add(std::to_string(i).c_str());
    }
}

/**
 * @brief Callback function to handle the "Add" button click event.
 * 
 * Validates the input fields, converts the data to appropriate types,
 * and adds the budget to the system. If successful, a success message is shown.
 * 
 * @param widget The FLTK widget triggering the callback.
 * @param data The data passed with the callback, in this case, the current window.
 */
void UiAddBudgetWindow::add_callback(Fl_Widget* widget, void* data) {
    UiAddBudgetWindow* window = (UiAddBudgetWindow*)data;

    std::string name = window->nameInput->value();
    std::string startingDay = window->dayChoiceStart->text();
    std::string endingDay = window->dayChoiceEnd->text();
    std::string startingMonth = window->monthChoiceStart->text();
    std::string endingMonth = window->monthChoiceEnd->text();
    std::string startingYear = window->yearChoiceStart->text();
    std::string endingYear = window->yearChoiceEnd->text();
    std::string amountStr = window->amountInput->value();
    std::string source = window->sourceInput->value();

    if (name.empty() || startingDay.empty() || endingDay.empty() || startingMonth.empty() || endingMonth.empty() ||
        startingYear.empty() || endingYear.empty() || amountStr.empty() || source.empty()) 
    {
        fl_alert("All fields must be filled out.");
        return;
    }

    double amount = std::stod(amountStr); // Convert string to double

    // Ensure the start date string is in the format YYYY-MM-DD HH:MM:SS
    std::ostringstream startDateStream;
    startDateStream << startingYear << "-"
                    << std::setw(2) << std::setfill('0') << window->monthChoiceStart->value() + 1 << "-"
                    << std::setw(2) << std::setfill('0') << std::stoi(startingDay) << " 00:00:00";
    std::string start = startDateStream.str();
    std::cout << "Start Date: " << start << std::endl;

    // Convert the start date string to a time_point
    auto startT = DateUtils::stringToTimePoint(start);

    // Ensure the end date string is in the format YYYY-MM-DD HH:MM:SS
    std::ostringstream endDateStream;
    endDateStream << endingYear << "-"
                  << std::setw(2) << std::setfill('0') << window->monthChoiceEnd->value() + 1 << "-"
                  << std::setw(2) << std::setfill('0') << std::stoi(endingDay) << " 23:59:59";
    std::string end = endDateStream.str();
    std::cout << "End Date: " << end << std::endl;

    // Convert the end date string to a time_point
    auto endT = DateUtils::stringToTimePoint(end);

    User& user = FileManager::getMainUser();
    Budget budget(user.getBudgetCount() + 1, name, amount, 0, startT, endT, source);
    
    ExpenseManager::addBudget(budget);
    FileManager::saveDataToFile(&user);

    std::cout << "Budget added: " << name << ", " << amount << ", " << start << ", " << end << ", " << source << std::endl;
    fl_message("Budget added successfully.");

    window->hide();

    UiBudgetWindow* budget_window = new UiBudgetWindow(window->w(), window->h());
    budget_window->show();
}

/**
 * @brief Callback function to handle the "Cancel" button click event.
 * 
 * Hides the current window and opens the main budget window.
 * 
 * @param widget The FLTK widget triggering the callback.
 * @param data The data passed with the callback, in this case, the current window.
 */
void UiAddBudgetWindow::cancel_callback(Fl_Widget* widget, void* data) {
    UiAddBudgetWindow* window = (UiAddBudgetWindow*)data;
    window->hide();

    UiBudgetWindow* budget_window = new UiBudgetWindow(window->w(), window->h());
    budget_window->show();
}
