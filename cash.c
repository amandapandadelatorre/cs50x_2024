#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change;

    do
    {
        change = get_int("How much change is owed? ");
    }
    while(change <= 0);

    const int quarters = change / 25;
    change -= quarters * 25;

    const int dimes = change / 10;
    change -= dimes * 10;

    const int nickels = change / 5;
    change -= nickels *5;

    const int pennies = change / 1;
    change -= pennies;

    // Print how many of coins are necessary
    int totalCoins = quarters + dimes + nickels + pennies;
    printf("Total coins needed: %i\n", totalCoins);
}
