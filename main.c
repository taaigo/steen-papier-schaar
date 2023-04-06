#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generate_random()
{
    srand(time(NULL));
    int random_number = rand() % 3;
    switch (random_number)
    {
        case 0:
            return "steen";
            break;
        case 1:
            return "papier";
            break;
        case 2:
            return "schaar";
            break;
    }
}

int check_winner(char* user, char* computer)
{
    if (strcmp(computer, "steen") == 0)
    {
        if (strcmp(user, "steen") == 0)
        {
            return 2;
        }
        else if (strcmp(user, "papier") == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(computer, "papier") == 0)
    {
        if (strcmp(user, "steen") == 0)
        {
            return 0;
        }
        else if (strcmp(user, "papier") == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else if (strcmp(computer, "schaar") == 0)
    {
        if (strcmp(user, "steen") == 0)
        {
            return 1;
        }
        else if (strcmp(user, "papier") == 0)
        {
            return 0;
        }
        else
        {
            return 2;
        }
    }
}

int main()
{
    char input[6];
    char* computer_choice;
    int win;
    int cont = 1;

    while (cont == 1)
    {
        printf("Welkom bij steen papier schaar!\n(steen,papier,schaar): ");
        scanf("%s", input);
        computer_choice = generate_random();
        printf("de computer heeft gekozen voor %s\n", computer_choice);
        win = check_winner(input, computer_choice);
        
        switch (win)
        {
            case 0:
                printf("Je hebt verloren.\n");
                break;
            case 1:
                printf("Je hebt gewonnen!\n");
                break;
            case 2:
                printf("Het is geleikspel.\n");
                break;
        }
        printf("Wil je opnieuw spelen?\n(ja/nee): ");
        scanf("%s", input);
        if (strcmp(input, "ja") == 0)
        {
            cont = 1;
        }
        else
        {
            cont = 0;
        }
    }
    return 0;
}
