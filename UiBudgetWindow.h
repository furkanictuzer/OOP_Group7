#ifndef UI_BUDGET_WINDOW_H
#define UI_BUDGET_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Button.H>

#include <vector>
#include <sstream>

#include "Budget.h"
#include "Expense.h"
#include "Category.h"
#include "FileManager.h"
#include "UiMainWindow.h"
#include "UiAddBudgetWindow.h"

/**
 * @class UiBudgetWindow
 * @brief A window for managing budgets within the application.
 * 
 * This class is responsible for providing a graphical user interface (GUI)
 * for viewing, adding, and managing budgets. The user can view the list of
 * existing budgets, add new ones, and close the window. It uses the FLTK 
 * library to create the window and its widgets.
 */
class UiBudgetWindow : public Fl_Window
{
private:
    Fl_Browser* budgetBrowser; ///< Browser widget to display the list of budgets.
    Fl_Button* newBudgetButton; ///< Button to open the "Add New Budget" window.
    Fl_Button* closeButton; ///< Button to close the current window.

    /**
     * @brief Callback function to handle the event when the "Close" button is clicked.
     * 
     * This function closes the budget window without making any changes.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void close_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Callback function to handle the event when the "New Budget" button is clicked.
     * 
     * This function opens the "Add New Budget" window to allow the user
     * to create a new budget.
     * 
     * @param widget The widget that triggered the callback.
     * @param data Additional data passed to the callback.
     */
    static void new_budget_callback(Fl_Widget* widget, void* data);

    /**
     * @brief Populates the budget list with existing budgets.
     * 
     * This method will retrieve all budgets from the system and display them
     * in the budget browser widget.
     */
    void populateBudgets();

public:
    /**
     * @brief Constructs the window for managing budgets.
     * 
     * Initializes the window with appropriate sizes and sets up the widgets
     * including the budget browser and buttons.
     * 
     * @param width The width of the window.
     * @param height The height of the window.
     */
    UiBudgetWindow(int width, int height);

    /**
     * @brief Destructor for cleaning up resources.
     */
    ~UiBudgetWindow();
};

#endif //!UI_BUDGET_WINDOW_H
