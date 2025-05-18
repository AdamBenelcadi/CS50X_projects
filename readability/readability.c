#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num_word_detec(string Text);
int num_sentence_detec(string Text);
int num_letter_detec(string Text);

int main(void)
{
    string Txt = get_string("Text: ");
    int spaces = num_word_detec(Txt) - 1;
    if (num_word_detec(Txt) < 100)
    {
        float index = 0.0588 * ((float) (num_letter_detec(Txt) * 100) / num_word_detec(Txt)) -
                      0.296 * ((float) (num_sentence_detec(Txt) * 100) / num_word_detec(Txt)) -
                      15.8;
        if (index < 0)
        {
            printf("Before Grade 1\n");
        }
        if (index > 16)
        {
            printf("Grade 16+\n");
        }
        if (index > 0 && index < 16)
        {
            printf("Grade %i\n", (int) round(index));
        }
    }
}

int num_word_detec(string Text)
{
    int sum = 0;
    for (int i = 0; Text[i] != '\0'; i++)
    {
        if (Text[i] == ' ')
        {
            sum = sum + 1;
        }
    }
    return sum + 1;
}

int num_sentence_detec(string Text)
{
    int sum = 0;
    for (int i = 0; Text[i] != '\0'; i++)
    {
        if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
        {
            sum = sum + 1;
        }
    }
    return sum;
}

int num_letter_detec(string Text)
{
    int sum = 0;
    for (int i = 0; Text[i] != '\0'; i++)
    {
        if (Text[i] == 'a' || Text[i] == 'b' || Text[i] == 'c' || Text[i] == 'd' ||
            Text[i] == 'e' || Text[i] == 'f' || Text[i] == 'g' || Text[i] == 'h' ||
            Text[i] == 'i' || Text[i] == 'j' || Text[i] == 'k' || Text[i] == 'l' ||
            Text[i] == 'm' || Text[i] == 'n' || Text[i] == 'o' || Text[i] == 'p' ||
            Text[i] == 'q' || Text[i] == 'r' || Text[i] == 's' || Text[i] == 't' ||
            Text[i] == 'u' || Text[i] == 'v' || Text[i] == 'w' || Text[i] == 'x' ||
            Text[i] == 'y' || Text[i] == 'z' || Text[i] == 'A' || Text[i] == 'B' ||
            Text[i] == 'C' || Text[i] == 'D' || Text[i] == 'E' || Text[i] == 'F' ||
            Text[i] == 'G' || Text[i] == 'H' || Text[i] == 'I' || Text[i] == 'J' ||
            Text[i] == 'K' || Text[i] == 'L' || Text[i] == 'M' || Text[i] == 'N' ||
            Text[i] == 'O' || Text[i] == 'P' || Text[i] == 'Q' || Text[i] == 'R' ||
            Text[i] == 'S' || Text[i] == 'T' || Text[i] == 'U' || Text[i] == 'V' ||
            Text[i] == 'W' || Text[i] == 'X' || Text[i] == 'Y' || Text[i] == 'Z')
        {
            sum = sum + 1;
        }
    }
    return sum;
}
