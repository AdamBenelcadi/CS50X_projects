#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string rotate(string text, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        string plaintext = get_string("plaintext:  ");
        string ciphertext = rotate(plaintext, atoi(argv[1]));
        printf("ciphertext: %s\n", ciphertext);
        free(ciphertext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string rotate(string text, int key)
{
    int n = strlen(text);
    char *rotated = malloc((n + 1) * sizeof(char)); // Allocate memory

    for (int i = 0; i < n; i++)
    {
        if (isupper(text[i]))
        {
            rotated[i] = (((text[i] - 'A' + key) % 26) + 'A');
        }
        else if (islower(text[i]))
        {
            rotated[i] = (((text[i] - 'a' + key) % 26) + 'a');
        }
        else
        {
            rotated[i] = text[i];
        }
    }
    rotated[n] = '\0'; // Null-terminate the string
    return rotated;
}
