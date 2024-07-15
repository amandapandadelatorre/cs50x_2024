#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    int j;
    int n;

    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n >= 9);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf(" #");
        }
        printf("\n");
    }
}
