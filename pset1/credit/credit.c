#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool luhn_valid(string card);
bool is_numeric(string s);

int main(void)
{
    string card;
    // Requests valid number else invalid
    do
    {
        card = get_string("Number: ");

        if (!is_numeric(card))
        {
            printf("INVALID\n");
        }
        else if (!luhn_valid(card))
        {
            printf("INVALID\n");
        }
    }
    while (!is_numeric(card) || !luhn_valid(card));

    int len = strlen(card);

    if (len == 15 && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
    {
        printf("AMEX\n");
    }
    else if (len == 16 && card[0] == '5' &&
             (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' ||
              card[1] == '5'))
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 || len == 16) && card[0] == '4')
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


// Uses Luhn's algorithm to validate credit card numbers.
// Doubles every second digit from the end, sums digits accordingly.
// Returns true if the total modulo 10 is 0 (valid checksum).
bool luhn_valid(string card)
{
    int sum_even = 0;
    int sum_odd = 0;
    int len = strlen(card);

    for (int i = len - 1; i >= 0; i--)
    {
        int digit = card[i] - '0';

        if ((len - 1 - i) % 2 == 0)
        {
            sum_odd += digit;
        }
        else
        {
            int product = digit * 2;
            sum_even += (product < 10) ? product : (product / 10 + product % 10);
        }
    }

    int total = sum_even + sum_odd;
    return (total % 10 == 0);
}
// Checks if input is numeric
bool is_numeric(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
    }
    return true;
}
