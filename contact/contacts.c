#include <cs50.h>
#include <stdio.h>

void print_contact(int number);
// Prompt
int main(void)
{
    int contact = get_int("How many contacts would you like to enter? ");
    for (int i = 0; i < contact; i++)
    {
        print_contact(i + 1);
    }
}

void print_contact(int number)
{
    // # of Contacts
    printf("\nContact %i:", number);

    // Name
    string name = get_string("\nName: ");
    // Age
    int age = get_int("Age: ");
    // Phone
    string phone = get_string("Phone: ");
    // Summary with Name(Age): Phone[UNDERAGE]
    if (age > 18)
    {
        printf("Summary:\n - %s (%i): %s\n", name, age, phone);
    }
    else
    {
        printf("- %s (%i): %s [UNDERAGE]\n", name, age, phone);
    }
}
