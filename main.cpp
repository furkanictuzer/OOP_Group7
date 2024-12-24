#include "User.h"
#include <iostream>
#include <cassert>
#include "FileManager.h"
#include "Category.h"
#include "Expense.h"
#include "ReportGenerator.h"
#include "DateUtils.h"
#include "AuthenticationManager.h"

void testFileManager() {
    FileManager fileManager;

    // Test 1: Dosya kaydetme
    User user(1, "furkan", "12345", 1500.0);
    Category food("Food");
    Category transport("Transport");

    Expense groceries(0, 100.0, DateUtils::stringToTimePoint("2021.05.01"), "Groceries", &food);
    Expense eatingOut(1, 200.0, DateUtils::stringToTimePoint("2021.05.02"), "Eating out", &food);

    Expense taxi(2, 50.0, DateUtils::stringToTimePoint("2021.05.02"), "Taxi", &transport);
    Expense bus(3, 20.0, DateUtils::stringToTimePoint("2021.05.03"), "Bus", &transport);

    food.addExpense(&groceries);
    food.addExpense(&eatingOut);

    transport.addExpense(&taxi);
    transport.addExpense(&bus);

    user.addCategory(food);
    user.addCategory(transport);

    std::cout << "Test 1: Saving data to file...\n";
    fileManager.saveDataToFile(&user);

    // Test 2: Dosya varlık kontrolü
    std::cout << "Test 2: Checking if file exists...\n";
    assert(fileManager.fileExists() && "File does not exist after saving!");

    // Test 3: Dosyadan veri yükleme
    std::cout << "Test 3: Loading data from file...\n";
    User loadedUser = fileManager.loadDataFromFile();

    // Test 4: Yüklenen veriyi kontrol etme
    std::cout << "Test 4: Verifying loaded data...\n";
    assert(loadedUser.getUserId() == user.getUserId() && "User ID mismatch!");
    assert(loadedUser.getUserName() == user.getUserName() && "Username mismatch!");
    assert(loadedUser.getBalance() == user.getBalance() && "Balance mismatch!");

    // Başarılı sonuç
    std::cout << "All tests passed successfully!\n";
}

void testReportGenerator() {
    User user(1, "furkan", "12345", 1500.0);
    Category food("Food");
    Category transport("Transport");

    Expense groceries(0, 100.0, DateUtils::stringToTimePoint("2021.05.01"), "Groceries", &food);
    Expense eatingOut(1, 200.0, DateUtils::stringToTimePoint("2021.05.02"), "Eating out", &food);

    Expense taxi(2, 50.0, DateUtils::stringToTimePoint("2021.05.02"), "Taxi", &transport);
    Expense bus(3, 20.0, DateUtils::stringToTimePoint("2021.05.03"), "Bus", &transport);

    food.addExpense(&groceries);
    food.addExpense(&eatingOut);

    transport.addExpense(&taxi);
    transport.addExpense(&bus);

    user.addCategory(food);
    user.addCategory(transport);

    ReportGenerator reportGenerator;

    auto startDate = DateUtils::stringToTimePoint("2021.05.01");
    auto endDate = DateUtils::stringToTimePoint("2021.05.07");

    std::cout << "Test 1: Generating weekly report...\n";
    Report weeklyReport = reportGenerator.generateWeeklyReport(user, startDate);
    assert(!weeklyReport.getExpenses().empty() && "Weekly report should not be empty!");

    std::cout << "Test 2: Generating monthly report...\n";
    Report monthlyReport = reportGenerator.generateMonthlyReport(user, startDate);
    assert(!monthlyReport.getExpenses().empty() && "Monthly report should not be empty!");

    std::cout << "Test 3: Generating annual report...\n";
    Report annualReport = reportGenerator.generateAnnualReport(user, startDate);
    assert(!annualReport.getExpenses().empty() && "Annual report should not be empty!");

    std::cout << "Test 4: Generating custom report...\n";
    Report customReport = reportGenerator.generateReport(user, startDate, endDate);
    assert(!customReport.getExpenses().empty() && "Custom report should not be empty!");

    std::cout << "Test 5: Generating category report...\n";
    Report categoryReport = reportGenerator.generateCategoryReport(food);
    assert(!categoryReport.getExpenses().empty() && "Category report should not be empty!");

    weeklyReport.generateFile();

    std::cout << "All ReportGenerator tests passed successfully!\n";
}

void testAuthenticationManager() {
    FileManager fileManager;
    AuthenticationManager authManager(fileManager);

    // Test 1: Successful login
    std::cout << "Test 1: Successful login...\n";
    assert(authManager.tryToRegister("furkan", "12345") && "Registration should be successful!");
    
    while (true) {
        std::cout << "Press any key to exit...\n";
        std::cin.get();
        break;
    }
    assert(authManager.tryToLogin("furkan", "12345") && "Login should be successful!");

    while (true) {
        std::cout << "Press any key to exit...\n";
        std::cin.get();
        break;
    }
    // Test 2: Failed login due to incorrect password
    std::cout << "Test 2: Failed login due to incorrect password...\n";
    assert(!authManager.tryToLogin("furkan", "wrongpassword") && "Login should fail due to incorrect password!");

    while (true) {
        std::cout << "Press any key to exit...\n";
        std::cin.get();
        break;
    }
    // Test 3: Failed login due to non-existent user
    std::cout << "Test 3: Failed login due to non-existent user...\n";
    assert(!authManager.tryToLogin("nonexistent", "password") && "Login should fail due to non-existent user!");

    // Test 4: Adding a new user and successful login
    std::cout << "Test 4: Adding a new user and successful login...\n";
    assert(authManager.tryToRegister("newuser", "newpassword") && "Registration should be successful!");
    assert(authManager.tryToLogin("newuser", "newpassword") && "Login should be successful for the new user!");

    std::cout << "All AuthenticationManager tests passed successfully!\n";
}

int main() {
    //testFileManager();
    //testReportGenerator();
    testAuthenticationManager();

    while (true) {
        std::cout << "Press any key to exit...\n";
        std::cin.get();
        break;
    }

    return 0;
}
