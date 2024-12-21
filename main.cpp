#include "User.h"
#include <iostream>
#include <cassert>
#include "FileManager.h"
#include "Category.h"

void testFileManager() {
    FileManager fileManager;

    // Test 1: Dosya kaydetme
    User user(1, "furkan27", "12345", 1500.0);
    user.addCategory(Category("Food"));
    user.addCategory(Category("Transport"));

    std::cout << "Test 1: Saving data to file...\n";
    fileManager.saveDataToFile(&user);

    // Test 2: Dosya varlık kontrolü
    //std::string filename = "user_data.json";
    std::cout << "Test 2: Checking if file exists...\n";
    assert(fileManager.fileExists() && "File does not exist after saving!");

    // Test 3: Dosyadan veri yükleme
    std::cout << "Test 3: Loading data from file...\n";
    User loadedUser(0, "", "", 0.0);
    fileManager.loadDataFromFile(loadedUser);

    // Test 4: Yüklenen veriyi kontrol etme
    std::cout << "Test 4: Verifying loaded data...\n";
    assert(loadedUser.getUserId() == user.getUserId() && "User ID mismatch!");
    assert(loadedUser.userInfo() == user.userInfo() && "Username mismatch!");
    assert(loadedUser.getBalance() == user.getBalance() && "Balance mismatch!");

    // Başarılı sonuç
    std::cout << "All tests passed successfully!\n";
}

int main() {
    testFileManager();
    return 0;
}
