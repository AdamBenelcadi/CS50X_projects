#include <cs50.h>
#include <stdio.h>

int num_sentence_detec(string Text);

int main(void)
{
    string Txt = get_string("Text: ");
    printf("%i\n", num_sentence_detec(Txt));
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
