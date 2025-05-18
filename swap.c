#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = get_int("x =  ");
    int y = get_int("y =  ");
    swap(&x, &y);
    printf("x =  %i y =  %i\n", x, y);

}

void swap(int *a, int *b)
{
    int z = *a;
    *a = *b;
    *b = z;
}
