# Personal Expense Tracker

A simple command-line expense tracking application written in C using only standard C libraries.

## Features

- **Add Expenses**: Record new expenses with amount, category, date, and description
- **View All Expenses**: Display all recorded expenses in a formatted table
- **Filter by Category**: View expenses filtered by specific categories
- **Calculate Totals**: View total expenses, count, and average expense amount
- **Menu-driven Interface**: Easy-to-use interactive menu system
- **Input Validation**: Robust input validation for numerical values

## Requirements

- GCC or Clang compiler
- Make (optional, for using Makefile)
- Standard C library (no external dependencies)

## Installation

1. Clone or download this repository
2. Compile the program using one of these methods:

### Using Make
```bash
make
```

### Manual Compilation
```bash
clang -Wall -Wextra -Werror -std=c99 -o expenseTracker expenseTracker.c
```

## Usage

Run the compiled program:
```bash
./expenseTracker
```

Follow the menu prompts to:
1. Add new expenses
2. View all expenses
3. Filter expenses by category
4. Calculate expense totals
5. Exit the program

## Data Format

- **Amount**: Floating-point number (e.g., 25.50) - must be positive
- **Category**: Text string (e.g., "Food", "Transportation", "Entertainment")
- **Date**: YYYY-MM-DD format (e.g., 2024-01-15)
- **Description**: Brief description of the expense

## Example Usage

```
=== Welcome to Personal Expense Tracker ===

=== Expense Tracker Menu ===
1. Add Expense
2. View All Expenses
3. View Expenses by Category
4. Calculate Total Expenses
5. Exit
Enter your choice: 1

=== Add New Expense ===
Enter amount: $25.50
Enter category: Food
Enter date (YYYY-MM-DD): 2024-01-15
Enter description: Lunch at restaurant
Expense added successfully!
```

## Features

- **Input Validation**: The program validates numerical input and will prompt for re-entry if invalid data is provided
- **Cross-platform**: Uses only standard C libraries, making it portable across different systems
- **Memory Safe**: Uses safe string functions to prevent buffer overflows

## Limitations

- Maximum of 100 expenses per session
- Data is not persistent (resets when program exits)
- No data validation for date format

## Future Improvements

- File-based data persistence
- Date format validation
- Export to CSV functionality
- Monthly/yearly reporting features
- Budget tracking and alerts 