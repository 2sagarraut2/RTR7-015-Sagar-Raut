#include <stdio.h>

int main(int agrc, char *argv[], char *envp[])
{

    int myAddition(int, int);

    int r, num01, num02, num03, num04;

    num01 = 10;
    num02 = 20;
    num03 = 30;
    num04 = 40;

    r = myAddition(myAddition(num01, num02), myAddition(num03, num04));

    printf("\n");
    printf("%d + %d + %d + %d = %d\n", num01, num02, num03, num04, r);

    printf("\n---End---\n\n");

    return (0);
}

int myAddition(int a, int b)
{
    int SR_sum;

    SR_sum = a + b;
    return (SR_sum);
}