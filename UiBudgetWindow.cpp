#include "UiBudgetWindow.h"

UiBudgetWindow::UiBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Budget Window")
{
    budgetBrowser = new Fl_Browser(20, 20, width - 40, height - 120);
    closeButton = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    newBudgetButton = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "New Budget");

    close_button->callback(close_callback, (void*)this);
    add_expense_button->callback(add_expense_callback, (void*)this);

    populateExpenses();

    end();
}

UiBudgetWindow::~UiBudgetWindow()
{
    delete budgetBrowser;
    delete closeButton;
    delete newBudgetButton;
}

void UiBudgetWindow::populateExpenses() {
    // Browser içeriğini temizle
    budgetBrowser->clear();

    // Bütçeler üzerinden dolaş
    for (const auto& budget : ExpenseManager::budgets) {
        // Bütçe bilgilerini oluştur
        std::ostringstream budgetInfo;
        budgetInfo << "Budget: " << budget.getName()
                   << " | Amount: " << std::fixed << std::setprecision(2) << budget.getBudgetAmount()
                   << " | Spent: " << budget.getSpentAmount()
                   << " | Source: " << budget.getSourcetDetails()
                   << " | Interval: " << budget.getTimeInterval();

        // Browser'a bütçe bilgilerini ekle
        budgetBrowser->add(budgetInfo.str().c_str());

        // Harcamalar üzerinden dolaş
        for (const auto& expense : ExpenseManager::expenses) {
            // Harcama bütçesiyle eşleşiyor mu kontrol et
            if (expense.getCategory() && expense.getCategory()->getCategoryName() == budget.getName()) {
                std::ostringstream expenseInfo;
                expenseInfo << "   - Expense: ID=" << expense.getId()
                            << " | Amount=" << std::fixed << std::setprecision(2) << expense.getAmount()
                            << " | Date=" << DateUtils::timePointToString(expense.getDate())
                            << " | Description=" << expense.getDescription();

                // Browser'a harcama bilgilerini ekle
                budgetBrowser->add(expenseInfo.str().c_str());
            }
        }
    }
}

void UiBudgetWindow::close_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;
    window->hide();

    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

void UiBudgetWindow::add_expense_callback(Fl_Widget* widget, void* data) 
{
    UiBudgetWindow* window = (UiBudgetWindow*)data;

    //UiAddBudgetWindow class wil be written
    UiAddBudgetWindow* add_budget_window = new UiAddBudgetWindow(window->w(), window->h());
    add_budget_window->show();
}
