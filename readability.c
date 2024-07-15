#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int letterCount(string);
int wordCount(string);
int sentenceCount(string);
float averagePer100(int, int);

int main(void)
{
    // ask user for text
    string text = get_string("Text: ");

    // get the counts of letters, words, and sentences
    int letters = letterCount(text);
    int words = wordCount(text);
    int sentences = sentenceCount(text);

    // calculate the averages
    const float L = averagePer100(letters, words);
    const float S = averagePer100(sentences, words);
    const float readingLevel = round(0.0588 * L - 0.296 * S - 15.8);

    // print the grade
    if (readingLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readingLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)readingLevel);
    }

}

// get the average per 100 for 2 ints
float averagePer100(int x, int y)
{
    return ((float)x / y) * 100;
}

// count how many letters are in a string
int letterCount(string text)
{
    int count = 0;

    // loop through each character
    for (int i = 0; text[i] != '\0'; i++) {
        // Check if the character is a letter
        if (isalpha(text[i])) {
            count++;
        }
    }

    return count;
}

// count how many words are in a string
int wordCount(string text)
{
    int count = 0;

    // loop through each character
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }

    return count + 1;
}

// count how many sentences are in a string
int sentenceCount(string text)
{
    int count = 0;

    // loop through each character
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }

    return count ;
}
