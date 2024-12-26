#include "UiMainWindow.h"
#include "NotificationManager.h"
#include "MockClock.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <thread>
#include <chrono>
#include <ctime>
#include <iostream>

UiMainWindow::UiMainWindow(int width, int height)
    : Fl_Window(width, height, ("Main Window - " + FileManager::getMainUser().getUserName()).c_str()) {
    expenses_button = new Fl_Button(50, 50, 200, 40, "Expenses");
    set_budget_button = new Fl_Button(50, 100, 200, 40, "Set Budget");
    my_categories_button = new Fl_Button(50, 150, 200, 40, "My Categories");
    get_report_button = new Fl_Button(50, 200, 200, 40, "Get Report");
    profile_button = new Fl_Button(300, 50, 100, 40, "Profile");

    expenses_button->callback(button_callback, (void*)this);
    set_budget_button->callback(button_callback, (void*)this);
    my_categories_button->callback(button_callback, (void*)this);
    get_report_button->callback(button_callback, (void*)this);
    profile_button->callback(button_callback, (void*)this);

    // Tarih göstermek için kutu
    date_display = new Fl_Box(50, 300, 300, 40, "Date: --");
    date_display->box(FL_UP_BOX);
    date_display->labelsize(14);
    date_display->labelfont(FL_BOLD + FL_ITALIC);
    date_display->labeltype(FL_SHADOW_LABEL);
    
    /*std::thread([date_display]() {
        while (true) {
            // 5 saniyede bir bir gün ilerlet
            MockClock::advanceTime(std::chrono::hours(24));

            // Tarihi al
            auto current_time = MockClock::getCurrentTime();
            std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);
            std::ostringstream oss;
            oss << std::put_time(std::localtime(&current_time_t), "%Y-%m-%d %H:%M:%S");
            std::string date_string = oss.str();

            // GUI'yi güncelle
            Fl::lock();
            date_display->label(("Date: " + date_string).c_str());
            Fl::unlock();
            Fl::awake();

            std::this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniyede bir çalıştır
        }
    }).detach();*/

    end();
}

UiMainWindow::~UiMainWindow() 
{
    delete expenses_button;
    delete set_budget_button;
    delete my_categories_button;
    delete get_report_button;
    delete profile_button;

    delete date_display;
}

void UiMainWindow::button_callback(Fl_Widget* widget, void* data) {
    UiMainWindow* window = (UiMainWindow*)data;
    
    if (widget == window->expenses_button) {
        std::cout << "Expenses button clicked" << std::endl;
        window->navigateToExpense();
    } else if (widget == window->set_budget_button) {
        std::cout << "Set Budget button clicked" << std::endl;
        window->navigateToBudget();
    } else if (widget == window->my_categories_button) {
        std::cout << "My Categories button clicked" << std::endl;
        window->navigateToCategories();
    } else if (widget == window->get_report_button) {
        std::cout << "Get Report button clicked" << std::endl;
        window->navigateToReport();
    } else if (widget == window->profile_button) {
        std::cout << "Profile button clicked" << std::endl;
        window->navigateToProfile();
    }
}

void UiMainWindow::navigateToExpense() {
    this->hide();

    UiExpenseWindow* expense_window = new UiExpenseWindow(this->w(), this->h());
    expense_window->show();
}

void UiMainWindow::navigateToBudget() {
    this->hide();

    UiBudgetWindow* budget_window = new UiBudgetWindow(this->w(), this->h());
    budget_window->show();
}

void UiMainWindow::navigateToCategories() {
    this->hide();

    UiCategoryWindow* category_window = new UiCategoryWindow(this->w(), this->h());
    category_window->show();
}

void UiMainWindow::navigateToReport() {
    this->hide();

    UiReportsWindow* reports_window = new UiReportsWindow(this->w(), this->h());
    reports_window->show();
}

void UiMainWindow::navigateToProfile() {
    this->hide();

    UiProfileWindow* profile_window = new UiProfileWindow(this->w(), this->h());
    profile_window->show();
}
