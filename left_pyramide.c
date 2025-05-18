#include <stdio.h>
#include <cs50.h>

void print_row(int len);

int main(void)
{
    int row = get_int("length: ");
    for(int j=1; j<row; j++)
    {
        print_row(j);

    }

}

void print_row(int len)
{
    for(int i=0; i<len; i++)
    {
        printf("#");
    }
    printf("\n");
}
