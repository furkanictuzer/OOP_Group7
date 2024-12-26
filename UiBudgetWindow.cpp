#include "UiBudgetWindow.h"

/**
 * @class UiBudgetWindow
 * @brief A window for managing and displaying budgets.
 * 
 * This class provides functionality to display the list of budgets and allows users to manage them.
 */
UiBudgetWindow::UiBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Budget Window")
{
    // Create the browser widget to display budgets
    budgetBrowser = new Fl_Browser(20, 20, width - 40, height - 120);

    // Create buttons for closing and adding new budgets
    closeButton = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    newBudgetButton = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "New Budget");

    // Set callback functions for the buttons
    closeButton->callback(close_callback, (void*)this);
    newBudgetButton->callback(new_budget_callback, (void*)this);

    // Populate the budget list
    populateBudgets();

    // Finalize the window setup
    end();
}

/**
 * @brief Destructor for UiBudgetWindow.
 * 
 * Cleans up the resources allocated for the budget window.
 */
UiBudgetWindow::~UiBudgetWindow()
{
    delete budgetBrowser;
    delete closeButton;
    delete newBudgetButton;
}

/**
 * @brief Populates the budget browser with the current user's budget information.
 * 
 * This function retrieves the user's budgets and displays them in the budget browser.
 */
void UiBudgetWindow::populateBudgets() 
{
    // Clear the current contents of the browser
    budgetBrowser->clear();

    // Get the main user
    User& user = FileManager::getMainUser();

    // Iterate over the user's budgets and display each one
    for (const auto& budget : user.getBudgets()) 
    {
        // Format the budget information
        std::ostringstream budgetInfo;
        budgetInfo << "\n\n "
                   << "Budget: " << budget.getName()
                   << " | Amount: " << std::fixed << std::setprecision(2) << budget.getBudgetAmount()
                   << " | Spent: " << budget.getSpentAmount()
                   << " | Source: " << budget.getSourceDetails()
                   << " | Interval: " << budget.getTimeInterval();

        // Add the formatted budget information to the browser
        budgetBrowser->add(budgetInfo.str().c_str());
    }
}

/**
 * @brief Callback function to close the current budget window and return to the main window.
 * 
 * This function is triggered when the close button is clicked.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiBudgetWindow::close_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    // Create and show the main window
    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

/**
 * @brief Callback function to open the window for adding a new budget.
 * 
 * This function is triggered when the "New Budget" button is clicked.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiBudgetWindow::new_budget_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    // Create and show the window to add a new budget
    UiAddBudgetWindow* add_budget_window = new UiAddBudgetWindow(window->w(), window->h());
    add_budget_window->show();
}
