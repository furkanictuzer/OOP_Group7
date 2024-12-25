#include "UiAddBudgetWindow.h"

UiAddBudgetWindow::UiAddBudgetWindow(int width, int height)
    : Fl_Window(width, height, "Add Budget Window") 
{
    nameInput = new Fl_Input(120, 20, 200, 30, "Name: ");
    dayChoiceStart = new Fl_Choice(120, 60, 60, 30, "Starting Day:");
    monthChoiceStart = new Fl_Choice(260, 60, 60, 30, "Starting Month:");
    yearChoiceStart = new Fl_Choice(400, 60, 60, 30, "Starting Year:");

    dayChoiceEnd = new Fl_Choice(120, 100, 60, 30, "Ending Day: ");
    monthChoiceEnd = new Fl_Choice(260, 100, 60, 30, "Ending Month: ");
    yearChoiceEnd = new Fl_Choice(400, 100, 60, 30, "Ending Year: ");

    amountInput = new Fl_Input(120, 140, 200, 30, "Amount: ");
    sourceInput = new Fl_Input(120, 180, 200, 30, "Source: ");

    addButton = new Fl_Button(120, 210, 90, 30, "Add");
    cancelButton = new Fl_Button(220, 210, 90, 30, "Cancel");

    addButton->callback(add_callback, (void*)this);
    cancelButton->callback(cancel_callback, (void*)this);

    populateDateChoices();

    end();
}

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

void UiAddBudgetWindow::add_callback(Fl_Widget* widget, void* data) {
    UiAddBudgetWindow* window = (UiAddBudgetWindow*)data;

    string name = window->nameInput->value();
    string startingDay = window->dayChoiceStart->text();
    string endingDay = window->dayChoiceEnd->text();
    string startingMonth = window->monthChoiceStart->text();
    string endingMonth = window->monthChoiceEnd->text();
    string startingYear = window->yearChoiceStart->text();
    string endingYear = window->yearChoiceEnd->text();
    string amountStr = window->amountInput->value();
    string source = window->sourceInput->value();

    if (name.empty() || startingDay.empty() || endingDay.empty() || startingMonth.empty() || endingMonth.empty() ||
                        startingYear.empty() || endingYear.empty() || amountStr.empty() || source.empty()) 
    {
        fl_alert("All fields must be filled out.");
        return;
    }

    double amount = stod(amountStr);//Convert string to double
    string startDate = startingYear + "-" + startingMonth + "-" + startingDay;
    string endDate = endingYear + "-" + endingMonth + "-" + endingDay;

    User& user = FileManager::getMainUser();

    Budget budget(name, amount, startDate, endDate, source);
    
    ExpenseManager::addBudget(budget);

    cout << "Budget added: " << name << ", " << amount << ", " << source << ", " << startDate << " - " << endDate << endl;
    fl_message("Budget saved successfully.");

    window->hide();
}

void UiAddBudgetWindow::cancel_callback(Fl_Widget* widget, void* data) {
    UiAddBudgetWindow* window = (UiAddBudgetWindow*)data;
    window->hide();
}