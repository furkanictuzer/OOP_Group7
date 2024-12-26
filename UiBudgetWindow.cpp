#include "UiBudgetWindow.h"

UiBudgetWindow::UiBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Budget Window")
{
    budgetBrowser = new Fl_Browser(20, 20, width - 40, height - 120);
    closeButton = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    newBudgetButton = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "New Budget");

    closeButton->callback(close_callback, (void*)this);
    newBudgetButton->callback(new_budget_callback, (void*)this);

    populateBudgets();

    end();
}

UiBudgetWindow::~UiBudgetWindow()
{
    delete budgetBrowser;
    delete closeButton;
    delete newBudgetButton;
}

void UiBudgetWindow::populateBudgets() 
{
    // Clear the browser content
    budgetBrowser->clear();

    User& user = FileManager::getMainUser();

    // Iterate over budgets
    for (const auto& budget : user.getBudgets()) 
    {
        // Create budget information string
        std::ostringstream budgetInfo;
        budgetInfo << "\n\n "
                   <<"Budget: " << budget.getName()
                   << " | Amount: " << std::fixed << std::setprecision(2) << budget.getBudgetAmount()
                   << " | Spent: " << budget.getSpentAmount()
                   << " | Source: " << budget.getSourceDetails()
                   << " | Interval: " << budget.getTimeInterval();

        // Add budget information to the browser
        budgetBrowser->add(budgetInfo.str().c_str());
    }
}

void UiBudgetWindow::close_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

void UiBudgetWindow::new_budget_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    UiAddBudgetWindow* add_budget_window = new UiAddBudgetWindow(window->w(), window->h());
    add_budget_window->show();
}
