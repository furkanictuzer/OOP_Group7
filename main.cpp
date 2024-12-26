#include "User.h"
#include <iostream>
#include <cassert>
#include <FL/Fl.H>
#include <thread>
#include <chrono>
#include <ctime>
#include "UiLoginWindow.h"
#include "FileManager.h"
#include "Category.h"
#include "Expense.h"
#include "ReportGenerator.h"
#include "DateUtils.h"
#include "AuthenticationManager.h"
#include "UiRegisterWindow.h"
#include "MockClock.h"
#include "NotificationManager.h"

int main(int argc, char** argv) {
    AuthenticationManager authenticationManager;
    
    UiRegisterWindow* register_window = new UiRegisterWindow(800, 500, &authenticationManager);
    register_window->show(argc, argv);

    MockClock::initialize();

    /*thread([]() {
        while (true) {
            // 5 saniyede bir bir gün ilerlet
            MockClock::advanceTime(std::chrono::hours(24));

            // Tarihi al
            auto current_time = MockClock::getCurrentTime();
            std::time_t current_time_t = std::chrono::system_clock::to_time_t(current_time);
            std::string date_string = std::ctime(&current_time_t);
            date_string.pop_back(); // Sondaki yeni satır karakterini kaldır

            // Bildirim kontrolü
            NotificationManager::checkBudgets();
            NotificationManager::checkExpenses();

            this_thread::sleep_for(std::chrono::seconds(5)); // 5 saniyede bir çalıştır
        }
    }).detach();*/

    return Fl::run();
}
