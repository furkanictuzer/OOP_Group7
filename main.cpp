#include "User.h"
#include <iostream>
#include <cassert>
#include "FileManager.h"
#include "Category.h"
#include "Expense.h" 

void testFileManager() {
    FileManager fileManager;

    // Test 1: Dosya kaydetme
    User user(1, "furkan", "12345", 1500.0);
    Category food("Food");
    Category transport("Transport");

    Expense groceries(0, 100.0, "2021.05.01", "Groceries", &food);
    Expense eatingOut(1, 200.0, "2021.05.02", "Eating out", &food);

    Expense taxi(2, 50.0, "2021.05.02", "Taxi", &transport);
    Expense bus(3, 20.0, "2021.05.03", "Bus", &transport);
    

    food.addExpense(&groceries);
    food.addExpense(&eatingOut);

    transport.addExpense(&taxi);
    transport.addExpense(&bus);

    user.addCategory(food);
    user.addCategory(transport);

    std::cout << "Test 1: Saving data to file...\n";
    fileManager.saveDataToFile(&user);

    // Test 2: Dosya varlık kontrolü
    //std::string filename = "user_data.json";
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

int main() {
    testFileManager();

    while (true) {
        // Kullanıcı uygulamayı elle kapatmalı
    }

    return 0;
}
