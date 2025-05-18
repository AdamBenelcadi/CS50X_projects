#include <cs50.h>
#include <stdio.h>

void print_row(int i);

int main(void)
{
    int height;
    do
    {
        height = get_int("height between 1 and 8: ");
    }
    while (height < 1 || height > 8);
    print_row(height);
}

void print_row(int h)
{
    for (int i = 1; i < h; i++)
    {
        for (int j = 0; j < h - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
