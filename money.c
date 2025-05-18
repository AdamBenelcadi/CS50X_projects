#include <cs50.h>
#include <stdio.h>

void print_row(int length);

int main(void)
{
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);
    for (int y = 0; y < Height; y++)
    {
        for (int w = Height - y; w > 0; w--)
        {
            printf(" ");
        }
        print_row(y + 1);
        printf("\n");
    }
}

void print_row(int length)
{
    for (int x = 0; x < length; x++)
    {
        printf("#");
    }
}
