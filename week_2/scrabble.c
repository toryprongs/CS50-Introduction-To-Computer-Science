#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int score_points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                          1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string word = get_string("Player 1: ");
    int total = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        char ch = word[i];

        if (isalpha(ch))
        {
            ch = toupper(ch);
            int index = ch - 'A';
            total += score_points[index];
        }
    }

    string word2 = get_string("Player 2: ");
    int total2 = 0;

    for (int i = 0; i < strlen(word2); i++)
    {
        char ch = word2[i];

        if (isalpha(ch))
        {
            ch = toupper(ch);
            int index = ch - 'A';
            total2 += score_points[index];
        }
    }

    if (total > total2)
        printf("Player 1 wins!\n");
    else if (total2 > total)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
    return 0;
}
