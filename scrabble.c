#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int calculatePoints(string);
const int SCORE[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{
    string question = "What word do you want to play?";
    string player1 = get_string("%s ", question);
    string player2 = get_string("%s ", question);

    int player1Points = calculatePoints(player1);
    int player2Points = calculatePoints(player2);

    if (player1Points > player2Points)
    {
        printf("Player 1 wins!\n");
    }
    else if (player1Points < player2Points)
    {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie!\n");
    }

}

int calculatePoints(string word)
{
    int points = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        points += SCORE[toupper(word[i]) - 'A'];
    }

    return points;
}
