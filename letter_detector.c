#include <cs50.h>
#include <stdio.h>
#include<string.h>

int num_letter_detec(string Text);

int main(void)
{
    string Txt = get_string("TEXT: ");
    printf("%i\n", num_letter_detec(Txt));
}

int num_letter_detec(string Text)
{
    int sum = 0;
    for (int i = 0; Text[i] != '\0'; i++)
    {
        if (Text[i] == 'a' || Text[i] == 'b' || Text[i] == 'c' || Text[i] == 'd' || Text[i] == 'e' || Text[i] == 'f' || Text[i] == 'g' || Text[i] == 'h' || Text[i] == 'i' || Text[i] == 'j' || Text[i] == 'k' || Text[i] == 'l' || Text[i] == 'm' || Text[i] == 'n' || Text[i] == 'o' || Text[i] == 'p' || Text[i] == 'q' || Text[i] == 'r' || Text[i] == 's' || Text[i] == 't' || Text[i] == 'u' || Text[i] == 'v' || Text[i] == 'w' || Text[i] == 'x' || Text[i] == 'y' || Text[i] == 'z' || Text[i] == 'A' || Text[i] == 'B' || Text[i] == 'C' || Text[i] == 'D' || Text[i] == 'E' || Text[i] == 'F' || Text[i] == 'G' || Text[i] == 'H' || Text[i] == 'I' || Text[i] == 'J' || Text[i] == 'K' || Text[i] == 'L' || Text[i] == 'M' || Text[i] == 'N' || Text[i] == 'O' || Text[i] == 'P' || Text[i] == 'Q' || Text[i] == 'R' || Text[i] == 'S' || Text[i] == 'T' || Text[i] == 'U' || Text[i] == 'V' || Text[i] == 'W' || Text[i] == 'X' || Text[i] == 'Y' || Text[i] == 'Z')
        {
            sum = sum + 1;
        }
    }
    return sum;
}
