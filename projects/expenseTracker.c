#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct
{
    float amount;
    char category[50];
    char date[11]; // Format: YYYY-MM-DD
    char description[100];
} Expense;

// Function prototypes
void addExpense(Expense expenses[], int *count);
void viewExpenses(Expense expenses[], int count);
void viewByCategory(Expense expenses[], int count);
void calculateTotal(Expense expenses[], int count);
void displayMenu(void);
int getInt(const char *prompt);
float getFloat(const char *prompt);

int main(void)
{
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    printf("=== Welcome to Personal Expense Tracker ===\n\n");

    do
    {
        displayMenu();
        choice = getInt("Enter your choice: ");

        switch(choice)
        {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                viewByCategory(expenses, expenseCount);
                break;
            case 4:
                calculateTotal(expenses, expenseCount);
                break;
            case 5:
                printf("Thank you for using Expense Tracker!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

void displayMenu(void)
{
    printf("=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. View Expenses by Category\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Exit\n");
}

int getInt(const char *prompt)
{
    int value;
    char buffer[100];
    
    do
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &value) == 1)
            {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid integer.\n");
    } while (1);
}

float getFloat(const char *prompt)
{
    float value;
    char buffer[100];
    
    do
    {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (sscanf(buffer, "%f", &value) == 1 && value >= 0)
            {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid positive number.\n");
    } while (1);
}

void addExpense(Expense expenses[], int *count)
{
    if (*count >= MAX_EXPENSES)
    {
        printf("Error: Maximum number of expenses reached!\n");
        return;
    }

    printf("\n=== Add New Expense ===\n");
    
    expenses[*count].amount = getFloat("Enter amount: $");
    
    printf("Enter category: ");
    fgets(expenses[*count].category, sizeof(expenses[*count].category), stdin);
    // Remove newline if present
    expenses[*count].category[strcspn(expenses[*count].category, "\n")] = 0;
    
    printf("Enter date (YYYY-MM-DD): ");
    fgets(expenses[*count].date, sizeof(expenses[*count].date), stdin);
    expenses[*count].date[strcspn(expenses[*count].date, "\n")] = 0;
    
    printf("Enter description: ");
    fgets(expenses[*count].description, sizeof(expenses[*count].description), stdin);
    expenses[*count].description[strcspn(expenses[*count].description, "\n")] = 0;

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count)
{
    if (count == 0)
    {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    printf("\n=== All Expenses ===\n");
    printf("%-12s %-15s %-12s %-20s\n", "Date", "Category", "Amount", "Description");
    printf("%-12s %-15s %-12s %-20s\n", "----", "--------", "------", "-----------");
    
    for (int i = 0; i < count; i++)
    {
        printf("%-12s %-15s $%-11.2f %-20s\n", 
               expenses[i].date, 
               expenses[i].category, 
               expenses[i].amount, 
               expenses[i].description);
    }
}

void viewByCategory(Expense expenses[], int count)
{
    if (count == 0)
    {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    char category[50];
    printf("\nEnter category to filter by: ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;

    printf("\n=== Expenses in Category: %s ===\n", category);
    printf("%-12s %-12s %-20s\n", "Date", "Amount", "Description");
    printf("%-12s %-12s %-20s\n", "----", "------", "-----------");
    
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(expenses[i].category, category) == 0)
        {
            printf("%-12s $%-11.2f %-20s\n", 
                   expenses[i].date, 
                   expenses[i].amount, 
                   expenses[i].description);
            found = 1;
        }
    }
    
    if (!found)
    {
        printf("No expenses found in category '%s'.\n", category);
    }
}

void calculateTotal(Expense expenses[], int count)
{
    if (count == 0)
    {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < count; i++)
    {
        total += expenses[i].amount;
    }

    printf("\n=== Expense Summary ===\n");
    printf("Total number of expenses: %d\n", count);
    printf("Total amount spent: $%.2f\n", total);
    printf("Average expense: $%.2f\n", total / count);
}