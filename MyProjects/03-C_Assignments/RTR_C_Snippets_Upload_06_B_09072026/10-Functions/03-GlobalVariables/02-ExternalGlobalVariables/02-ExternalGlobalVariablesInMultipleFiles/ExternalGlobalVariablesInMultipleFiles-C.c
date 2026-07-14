#include <stdio.h>

int SR_global_count = 0;

int main(void)
{
    void changeCount(void);
    void changeCountOne(void);
    void changeCountTwo(void);

    printf("\n");

    changeCount();
    changeCountOne();
    changeCountTwo();

    printf("\n---End---\n");

    return 0;
}

void changeCount(void)
{
    SR_global_count = SR_global_count + 1;
    printf("Global SR_count = %d\n", SR_global_count);
}