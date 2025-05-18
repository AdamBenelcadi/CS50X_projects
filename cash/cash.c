#include <cs50.h>
#include <stdio.h>

int n_coins1(int X);
int n_coins2(int Y);

int main(void)
{
    int Change_owed;
    do
    {
        Change_owed = get_int("Change owed: ");
    }
    while (Change_owed < 0);
    if (Change_owed >= 0 && Change_owed <= 25)
    {
        int result1 = n_coins1(Change_owed);
        printf("%i\n", result1);
    }
    if (Change_owed > 25)
    {
        int c = Change_owed / 25;
        int d = Change_owed % 25;
        if (d == 0)
        {
            printf("%i\n", c);
        }
        if (d > 0 && d < 25)
        {
            int s = c + n_coins2(d);
            printf("%i\n", s);
        }
    }
}

int n_coins1(int X)
{
    if (X == 0)
    {
        return 0;
    }
    else if (X == 25 || X == 10 || X == 5 || X == 1)
    {
        return 1;
    }

    else if (X > 1 && X < 5)
    {
        return X;
    }
    else if (X > 5 && X < 10)
    {
        return 1 + X - 5;
    }
    else if (X > 10 && X < 25)
    {
        int a = X / 10;
        int b = X % 10;
        if (b == 0)
        {
            return a;
        }
        else if (b == 1 || b == 5)
        {
            return a + 1;
        }
        else if (b > 1 && b < 5)
        {
            return a + b;
        }
        else if (b > 5 && b < 10)
        {
            return a + 1 + b - 5;
        }
    }
    return 0;
}

int n_coins2(int Y)
{
    if (Y == 10 || Y == 5 || Y == 1)
    {
        return 1;
    }
    else if (Y > 1 && Y < 5)
    {
        return Y;
    }
    else if (Y > 5 && Y < 10)
    {
        return 1 + Y - 5;
    }
    else if (Y > 10 && Y < 25)
    {
        int e = Y / 10;
        int f = Y % 10;
        if (f == 0)
        {
            return e;
        }
        else if (f == 1 || f == 5)
        {
            return e + 1;
        }
        else if (f > 1 && f < 5)
        {
            return e + f;
        }
        else if (f > 5 && f < 10)
        {
            return e + 1 + f - 5;
        }
    }
    return 0;
}
