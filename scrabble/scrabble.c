#include <cs50.h>
#include <stdio.h>

int char2int(char c);

int main(void)
{
    string Player1 = get_string("Player 1: ");
    string Player2 = get_string("Player 2: ");
    int sum1 = 0;
    for (int i = 0; Player1[i] != '\0'; i++)
    {
        char c = Player1[i];
        sum1 = sum1 + char2int(c);
    }
    int sum2 = 0;
    for (int j = 0; Player2[j] != '\0'; j++)
    {
        char d = Player2[j];
        sum2 = sum2 + char2int(d);
    }
    if (sum1 == sum2)
    {
        printf("Tie!\n");
    }
    else if (sum1 < sum2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

int char2int(char c)
{
    if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' || c == 'O' || c == 'R' ||
        c == 'S' || c == 'T' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'l' ||
        c == 'n' || c == 'o' || c == 'r' || c == 's' || c == 't' || c == 'u')
    {
        return 1;
    }
    else if (c == 'D' || c == 'G' || c == 'd' || c == 'g')
    {
        return 2;
    }
    else if (c == 'B' || c == 'C' || c == 'M' || c == 'P' || c == 'b' || c == 'c' || c == 'm' ||
             c == 'p')
    {
        return 3;
    }
    else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y' || c == 'f' || c == 'h' ||
             c == 'v' || c == 'w' || c == 'y')
    {
        return 4;
    }
    else if (c == 'K' || c == 'k')
    {
        return 5;
    }
    else if (c == 'J' || c == 'X' || c == 'j' || c == 'x')
    {
        return 8;
    }
    else if (c == 'Q' || c == 'Z' || c == 'q' || c == 'z')
    {
        return 10;
    }
    return 0;
}
