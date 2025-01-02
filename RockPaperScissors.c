#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

char playerInput[20];
int aiInputInt = 0;
int playerInputInt = 0;
bool valid = false;
char validOptions[][10] = {"rock", "paper", "scissors"};
char winner[10];
int playerScore = 0;
int aiScore = 0;
char playAgain[10] = "yes";


void checkValidInput()
{
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(playerInput, validOptions[i]) == 0)
        {
            valid = true;
            break;
        }
    }
}

void lowerCase()
{
    size_t len = strlen(playerInput); 
    for (size_t i = 0; i < len; i++)
    {
        playerInput[i] = (char)tolower(playerInput[i]);
    }
}

void checkWinner()
{
    if (playerInputInt == 1 && aiInputInt == 3)
    {
        strcpy(winner, "player");
    }
    else if (playerInputInt == 1 && aiInputInt == 2)
    {
        strcpy(winner, "ai");
    }
    else if (playerInputInt == 2 && aiInputInt == 1)
    {
        strcpy(winner, "player");
    }
    else if (playerInputInt == 2 && aiInputInt == 3)
    {
        strcpy(winner, "ai");
    }
    else if (playerInputInt == 3 && aiInputInt == 2)
    {
        strcpy(winner, "player");
    }
    else if (playerInputInt == 3 && aiInputInt == 1)
    {
        strcpy(winner, "ai");
    }
    else
    {
        strcpy(winner, "draw");
    }
}

void convertPlayerInputToInt()
{
    if (strcmp(playerInput, "rock") == 0)
    {
        playerInputInt = 1;
    }
    else if (strcmp(playerInput, "paper") == 0)
    {
        playerInputInt = 2;
    }
    else if (strcmp(playerInput, "scissors") == 0)
    {
        playerInputInt = 3;
    }
}

void playAgainLower()
{
    size_t len2 = strlen(playAgain); 
    for (size_t i = 0; i < len2; i++)
    {
        playAgain[i] = (char)tolower(playAgain[i]);
    }
}

int main()
{
    // 1 = rock, 2 = paper, 3 = scissors
    // 1 beats 3
    // 2 beats 1
    // 3 beats 2
    while (strcmp(playAgain, "yes") == 0)
    {
        while (!valid)
        {
            printf("Choose Rock Paper or Scissors\n");
            scanf("%s", playerInput);
            lowerCase();
            checkValidInput();
        }

        valid = false;

        srand((unsigned int)time(0));

        aiInputInt = (rand() % 3) + 1;

        convertPlayerInputToInt();
        checkWinner();

        if (strcmp(winner, "player") == 0)
        {
            playerScore++;
        }
        else if (strcmp(winner, "ai") == 0)
        {
            aiScore++;
        }

        printf("\nPlayer Score: %d\n", playerScore);
        printf("Ai Score: %d\n", aiScore);
        printf("Play Again?\n");
        scanf("%s", playAgain);
        playAgainLower();
    }
}