#ifndef UI_ADD_BUDGET_WINDOW_H
#define UI_ADD_BUDGET_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_ask.H>

#include <iostream>
#include <vector>
#include <sstream>

#include "Budget.h"
#include "Expense.h"
#include "Category.h"
#include "FileManager.h"
#include "UiMainWindow.h"
#include "UiAddExpenseWindow.h"
#include "UiBudgetWindow.h"
#include "DateUtils.h"

using namespace std;

/**
 * @class UiAddBudgetWindow
 * @brief A window to add a new budget in the application.
 * 
 * This class is responsible for providing a graphical user interface (GUI)
 * for adding a new budget. The user can specify details such as the budget's
 * name, start and end dates, amount, and source. It uses the FLTK library
 * for building the window and widgets.
 */
class UiAddBudgetWindow : public Fl_Window
{
private:
    Fl_Input* nameInput; ///< Input field for the budget name.
    Fl_Choice* dayChoiceStart; ///< Dropdown for selecting the start day.
    Fl_Choice* monthChoiceStart; ///< Dropdown for selecting the start month.
    Fl_Choice* yearChoiceStart; ///< Dropdown for selecting the start year.
    Fl_Choice* dayChoiceEnd; ///< Dropdown for selecting the end day.
    Fl_Choice* monthChoiceEnd; ///< Dropdown for selecting the end month.
    Fl_Choice* yearChoiceEnd; ///< Dropdown for selecting the end year.
    Fl_Input* amountInput; ///< Input field for the budget amount.
    Fl_Input* sourceInput; ///< Input field for the source of the budget.
    Fl_Button* cancelButton; ///< Button to cancel the budget addition.
    Fl_Button* addButton; ///< Button to add the new budget.

    /**
     * @brief Callback function to handle the event when the "Add" button is clicked.
     * 
     * This function retrieves the user's input and creates a new budget object.
     * It then saves the budget to the system.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void add_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to handle the event when the "Cancel" button is clicked.
     * 
     * This function closes the current window without making any changes.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void cancel_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Populates the date choices (day, month, year) with valid options.
     * 
     * This method will populate the drop-down menus for the start and end
     * dates with valid day, month, and year choices.
     */
    void populateDateChoices();

public:
    /**
     * @brief Constructs the window to add a budget.
     * 
     * Initializes the window with appropriate sizes and sets up the widgets.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiAddBudgetWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiAddBudgetWindow();
};

#endif //!UI_ADD_BUDGET_WINDOW_H
