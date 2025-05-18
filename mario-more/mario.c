#include <cs50.h>
#include <stdio.h>

void print_row(int length);

int main(void)
{
    print_row(5);
}

void print_row(int length)
{
    for( int x=0; x<length; x++)
    {
        printf("#");
    }
}
