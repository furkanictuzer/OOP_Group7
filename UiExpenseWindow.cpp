#include "UiExpenseWindow.h"

UiExpenseWindow::UiExpenseWindow(int width, int height)
    : Fl_Window(width, height, "Expenses") {
    expense_browser = new Fl_Browser(20, 20, width - 40, height - 120);
    close_button = new Fl_Button(width / 2 - 40, height - 50, 80, 30, "Close");
    add_expense_button = new Fl_Button(width / 2 - 40, height - 90, 80, 30, "Add Expense");

    close_button->callback(close_callback, (void*)this);
    add_expense_button->callback(add_expense_callback, (void*)this);

    populateExpenses();

    end();
}

UiExpenseWindow::~UiExpenseWindow() {
    delete expense_browser;
    delete close_button;
    delete add_expense_button;
}

void UiExpenseWindow::populateExpenses() {
    User& user = FileManager::getMainUser();
    const std::vector<Category>& categories = user.getCategories();

    for (const auto& category : categories) {
        std::stringstream category_header;
        category_header << "@bCategory: " << category.getCategoryName();
        expense_browser->add(category_header.str().c_str());

        const std::vector<Expense*>& expenses = category.getExpenses();
        for (const auto& expense : expenses) {
            std::stringstream expense_info;
            expense_info << "  - " << expense->getDescription() << ": $" << expense->getAmount() << " on " << DateUtils::timePointToString(expense->getDate());
            expense_browser->add(expense_info.str().c_str());
        }

        expense_browser->add("\n");
    }
}

void UiExpenseWindow::close_callback(Fl_Widget* widget, void* data) {
    UiExpenseWindow* window = (UiExpenseWindow*)data;
    window->hide();

    UiMainWindow* main_window = new UiMainWindow(window->w(), window->h());
    main_window->show();
}

void UiExpenseWindow::add_expense_callback(Fl_Widget* widget, void* data) 
{
    UiExpenseWindow* window = (UiExpenseWindow*)data;
    
    UiAddExpenseWindow* add_expense_window = new UiAddExpenseWindow(window->w(), window->h());
    add_expense_window->show();
}