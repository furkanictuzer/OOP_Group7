#Compiler
CXX = g++
CXXFLAGS = -std=c++11 -I C:\Users\HP\Documents\fltk-1.4.0-1-source\fltk-1.4.0-1 -I C:\fltk_build

# Linker Flags
LDFLAGS = -L C:\fltk_build\lib -lfltk -lcomctl32 -lole32 -luuid -lgdi32 -lws2_32 -lgdiplus -lwinspool -lcomdlg32

# Target
TARGET = makefileOutput.exe

# Source Files
SRC1 = AuthenticationManager.cpp Budget.cpp Category.cpp DateParser.cpp DateUtils.cpp Expense.cpp ExpenseManager.cpp 
SRC2 = FileManager.cpp MockClock.cpp NotificationManager.cpp RepeatedExpense.cpp Report.cpp ReportGenerator.cpp
SRC3 = UiAddBudgetWindow.cpp UiAddExpenseWindow.cpp UiBudgetWindow.cpp UiCategoryWindow.cpp UiExpenseWindow.cpp
SRC4 = UiLoginWindow.cpp UiMainWindow.cpp UiProfileWindow.cpp UiRegisterWindow.cpp UiReportsWindow.cpp User.cpp main.cpp

# Object files
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)
OBJ3 = $(SRC3:.cpp=.o)
OBJ4 = $(SRC4:.cpp=.o)

OBJS = $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4)

# Build Rules
all: $(TARGET)

$(OBJ1): $(SRC1)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ2): $(SRC2)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ3): $(SRC3)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ4): $(SRC4)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	del $(TARGET)