#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string);
string makeCipher(int, string);
char rotate(int, char);

int main(int argc, string argv[])
{
    // exit if the key does not exist or is longer than 1
    if (!(argv[1]) || argv[2] || (!(only_digits(argv[1]))))
    {
        return 1;
    }

    // get the key from the command line argument
    string key = argv[1];

    // make the key an int and ask for the plaintext
    const int K = atoi(key);
    const string P = get_string("Plaintext:  ");

    // init an empty array
    char cipher[strlen(P) + 1];

    // for each character in the plaintext,
    // rotate it the number of times defined in the key
    for (int i = 0, n = strlen(P); i < n; i++)
    {
        cipher[i] = rotate(K, P[i]);
    }

    // acount for nul
    cipher[strlen(P)] = '\0';
    printf("ciphertext: %s\n", cipher);

    return 0;
}

bool only_digits(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!(isdigit(key[i])))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }

    return true;
}

char rotate(int K, char P)
{
    if (isalpha(P))
    {
        char letter = isupper(P) ? 'A' : 'a';
        char rotatedLetter = ((P - letter + K) % 26 + 26) % 26 + letter;
        return rotatedLetter;
    }
    else
    {
        return P;
    }
}
