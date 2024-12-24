#Compiler
CC=gcc
CFLAGS = -Wall -Wextra -g -I./src/include

# Linker Flags
LDFLAGS = 

# Target
TARGET = main.exe

# Source Files
SRCS = AuthenticationManager.cpp Budget.cpp Category.cpp DateParser.cpp DateUtils.cpp Expense.cpp ExpenseManager.cpp FileManager.cpp MockClock.cpp NotificationManager.cpp RepeatedExpense.cpp Report.cpp ReportGenerator.cpp UiLoginWindow.cpp
User.cpp

# Build Rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET)