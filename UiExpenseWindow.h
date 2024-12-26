#ifndef UI_EXPENSE_WINDOW_H
#define UI_EXPENSE_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <sstream>

#include "Expense.h"
#include "Category.h"
#include "FileManager.h"
#include "UiMainWindow.h"
#include "UiAddExpenseWindow.h"

/**
 * @class UiExpenseWindow
 * @brief A window for displaying and managing expenses.
 * 
 * This class provides the user interface for viewing and adding expenses.
 * It uses the FLTK library to create the window and the necessary widgets
 * for expense management, including a browser to display existing expenses
 * and buttons to add or close the window.
 */
class UiExpenseWindow : public Fl_Window {
private:
    Fl_Browser* expense_browser; ///< Browser widget to display the list of expenses.
    Fl_Button* close_button; ///< Button to close the expense window.
    Fl_Button* add_expense_button; ///< Button to open the add expense window.

    /**
     * @brief Callback function for closing the window.
     * 
     * This function is triggered when the "Close" button is clicked.
     * It closes the current window.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void close_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function for adding a new expense.
     * 
     * This function is triggered when the "Add Expense" button is clicked.
     * It opens a new window for the user to add a new expense.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void add_expense_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Populates the expense browser with the list of expenses.
     * 
     * This function retrieves the expenses from the data store and updates
     * the browser widget to display the current list of expenses.
     */
    void populateExpenses();

public:
    /**
     * @brief Constructs the window for managing expenses.
     * 
     * Initializes the window with the appropriate size and sets up the
     * widgets for displaying expenses, adding a new expense, and closing the window.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiExpenseWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiExpenseWindow();
};

#endif // UI_EXPENSE_WINDOW_H
