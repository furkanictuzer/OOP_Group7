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

/**
 * @brief Main function that initializes the application.
 *
 * This function launches the user registration window, starts the time simulation,
 * and runs the FLTK event loop to process the GUI events.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return int The return value of the FLTK event loop.
 */

int main(int argc, char **argv)
{
    AuthenticationManager authenticationManager;

    /**
     * @brief Initializes the register window for user registration.
     *
     * This window allows the user to register by entering a username and password.
     */

    UiRegisterWindow *register_window = new UiRegisterWindow(800, 500, &authenticationManager);
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
