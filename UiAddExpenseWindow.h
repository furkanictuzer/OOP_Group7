#ifndef UI_ADD_EXPENSE_WINDOW_H
#define UI_ADD_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/fl_ask.H>

#include <iostream>
#include <string>
#include <vector>

#include "Category.h"
#include "DateUtils.h"
#include "ExpenseManager.h"
#include "FileManager.h"
#include "MockClock.h"
#include "UiMainWindow.h"
#include "DateUtils.h"
#include "ExpenseManager.h"
#include "FileManager.h"

/**
 * @class UiAddExpenseWindow
 * @brief A window to add a new expense in the application.
 * 
 * This class represents the UI window that allows the user to input details about a new expense, such as the amount,
 * category, date, description, and whether the expense is a repeated one. It also provides options to save or cancel the entry.
 */
class UiAddExpenseWindow : public Fl_Window {
private:
    /** Input field for the amount of the expense. */
    Fl_Input* amount_input;

    /** Dropdown list to select the category of the expense. */
    Fl_Choice* category_choice;

    /** Dropdown lists to select the day, month, and year of the expense date. */
    Fl_Choice* day_choice;
    Fl_Choice* month_choice;
    Fl_Choice* year_choice;

    /** Multiline input field for the description of the expense. */
    Fl_Multiline_Input* description_input;

    /** Checkbox to mark the expense as a repeated expense. */
    Fl_Check_Button* repeated_expense_check;

    /** Input field to specify the number of repetitions for a repeated expense. */
    Fl_Input* repeat_count_input;

    /** Button to save the entered expense. */
    Fl_Button* save_button;

    /** Button to cancel the operation. */
    Fl_Button* cancel_button;

    /**
     * @brief Callback function to handle the saving of an expense.
     * 
     * This function is called when the save button is clicked. It collects the data from the input fields and
     * adds the new expense to the system.
     * 
     * @param widget The widget that triggered the callback.
     * @param data A pointer to additional data (not used in this case).
     */
    static void save_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to handle the cancellation of the operation.
     * 
     * This function is called when the cancel button is clicked. It closes the window without saving any data.
     * 
     * @param widget The widget that triggered the callback.
     * @param data A pointer to additional data (not used in this case).
     */
    static void cancel_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to handle changes in the repeated expense checkbox.
     * 
     * This function is called when the user interacts with the checkbox for repeated expenses.
     * 
     * @param widget The widget that triggered the callback.
     * @param data A pointer to additional data (not used in this case).
     */
    static void repeated_expense_check_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Populates the date choices dropdowns (day, month, year).
     * 
     * This function initializes the day, month, and year dropdowns with valid date options.
     */
    void populateDateChoices();

public:
    /**
     * @brief Constructor to create the add expense window.
     * 
     * This constructor initializes the UI elements of the window (input fields, buttons, etc.) and sets up the window layout.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiAddExpenseWindow(int width, int height);

    /**
     * @brief Destructor to clean up the resources.
     * 
     * This destructor ensures proper cleanup of any dynamically allocated resources when the window is closed.
     */
    ~UiAddExpenseWindow();
};

#endif // UI_EXPENSE_WINDOW_H
