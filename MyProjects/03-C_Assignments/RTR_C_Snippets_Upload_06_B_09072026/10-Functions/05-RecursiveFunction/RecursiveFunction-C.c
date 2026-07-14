#include <stdio.h>

int main(void)
{

    unsigned int SR_num;

    void recursive(unsigned int);

    printf("Enter one number\n");
    scanf("%u", &SR_num);

    printf("\n\n");
    printf("Output of recursive function : \n\n");

    recursive(SR_num);

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