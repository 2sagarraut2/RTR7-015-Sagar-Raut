#include <stdio.h>

int SR_global_count = 0;

int main(void)
{

    void SR_change_count(void);
    void SR_change_count_one(void);
    void SR_change_count_two(void);

    printf("\n");

    SR_change_count();
    SR_change_count_one();
    SR_change_count_two();

    printf("\n---End---\n");

    return 0;
}

void SR_change_count(void)
{
    SR_global_count = SR_global_count + 1;
    printf("Global SR_count = %d\n", SR_global_count);
}