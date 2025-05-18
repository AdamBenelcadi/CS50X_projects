#include <cs50.h>
#include <stdio.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
    int score[N]; //In the function call average(N, score), you don't need to put brackets for score because score is already an array. When you pass an array to a function, you simply use the array name without brackets. This passes a pointer to the first element of the array to the function.
    for(int i=0; i<N; i++)
    {
        score[i]= get_int("score: ");
    }
    printf("average: %f\n", average(N, score)); //In the function call average(N, score), you don't need to put brackets for score because score is already an array. When you pass an array to a function, you simply use the array name without brackets. This passes a pointer to the first element of the array to the function.
}

float average(int length, int array[])
{
    int sum=0;
    for(int i=0; i<length; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float) length;
}
