#include <stdio.h>

int main(void)
{

    int a = 5;

    void changeCount(void);

    printf("\n");
    printf("A = %d\n\n", a);

    changeCount();

    return (0);

    printf("\n---End---\n");

    return (0);
}

void changeCount(void)
{
    static int SR_local_count = 0;

    SR_local_count = SR_local_count + 1;
    printf("Local SR_count = %d\n\n", SR_local_count);
}