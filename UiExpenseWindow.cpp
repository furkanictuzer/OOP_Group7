#include "UiExpenseWindow.h"

/**
 * @class UiExpenseWindow
 * @brief A window for displaying and managing expenses.
 * 
 * This class creates a window where users can view their expenses, categorized by 
 * different categories. It also provides the functionality to add new expenses.
 */
UiExpenseWindow::UiExpenseWindow(int width, int height)
    : Fl_Window(width, height, "Expenses") {
    // Create a browser to display expenses
    expense_browser = new Fl_Browser(20, 20, width - 40, height - 120);
    
    // Create buttons for closing the window and adding a new expense
    close_button = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    add_expense_button = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "Add Expense");

    // Set callback functions for the buttons
    close_button->callback(close_callback, (void*)this);
    add_expense_button->callback(add_expense_callback, (void*)this);

    // Populate the expense list
    populateExpenses();

    // Finalize window setup
    end();
}

/**
 * @brief Destructor for UiExpenseWindow.
 * 
 * This destructor cleans up the allocated resources for the expense window.
 */
UiExpenseWindow::~UiExpenseWindow() {
    delete expense_browser;
    delete close_button;
    delete add_expense_button;
}

/**
 * @brief Populates the expense list in the window.
 * 
 * This function retrieves the categories and expenses from the user's data 
 * and displays them in the expense browser widget.
 */
void UiExpenseWindow::populateExpenses() {
    // Get the current user and their categories
    User& user = FileManager::getMainUser();
    const std::vector<Category>& categories = user.getCategories();

    // Iterate through the categories and display them
    for (const auto& category : categories) {
        std::stringstream category_header;
        category_header << "@bCategory: " << category.getCategoryName();
        expense_browser->add(category_header.str().c_str());

        // Display each expense within the category
        const std::vector<Expense*>& expenses = category.getExpenses();
        for (const auto& expense : expenses) {
            std::stringstream expense_info;
            expense_info << "  - " << expense->getDescription() << ": $"
                         << expense->getAmount() << " on "
                         << DateUtils::timePointToString(expense->getDate());
            expense_browser->add(expense_info.str().c_str());
        }

        // Add an empty line after each category's expenses
        expense_browser->add("\n");
    }
}

/**
 * @brief Callback function for closing the expense window.
 * 
 * This function is triggered when the "Close" button is clicked. It hides the current 
 * window and returns to the main window.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiExpenseWindow::close_callback(Fl_Widget* widget, void* data) {
    UiExpenseWindow* window = (UiExpenseWindow*)data;
    window->hide();

    // Create and show the main window
    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

/**
 * @brief Callback function for adding a new expense.
 * 
 * This function is triggered when the "Add Expense" button is clicked. It hides 
 * the current window and opens the "Add Expense" window for entering a new expense.
 * 
 * @param widget The widget that triggered the callback.
 * @param data The window data.
 */
void UiExpenseWindow::add_expense_callback(Fl_Widget* widget, void* data) 
{
    UiExpenseWindow* window = (UiExpenseWindow*)data;
    window->hide();
    
    // Create and show the Add Expense window
    UiAddExpenseWindow* add_expense_window = new UiAddExpenseWindow(window->w(), window->h());
    add_expense_window->show();
}
