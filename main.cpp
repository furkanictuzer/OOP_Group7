#include "User.h"
#include <iostream>
#include <cassert>
#include <FL/Fl.H>
#include "UiLoginWindow.h"
#include "FileManager.h"
#include "Category.h"
#include "Expense.h"
#include "ReportGenerator.h"
#include "DateUtils.h"
#include "AuthenticationManager.h"
#include "UiRegisterWindow.h"

int main(int argc, char** argv) {

    FileManager fileManager;
    AuthenticationManager authenticationManager(fileManager);
    
    UiRegisterWindow* register_window = new UiRegisterWindow(800, 500, &authenticationManager);
    register_window->show(argc, argv);
    return Fl::run();
}
