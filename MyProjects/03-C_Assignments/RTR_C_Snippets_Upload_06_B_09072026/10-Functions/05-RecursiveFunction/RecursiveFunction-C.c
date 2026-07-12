#include <stdio.h>

int main(void)
{

    unsigned int num;

    void recursive(unsigned int);

    printf("Enter one number\n");
    scanf("%u", &num);

    printf("\n\n");
    printf("Output of recursive function : \n\n");

    recursive(num);

    printf("\n---End---\n");

    return (0);
}

void recursive(unsigned int n)
{

    printf("n = %d\n", n);

    if (n > 0)
    {
        recursive(n - 1);
    }
}