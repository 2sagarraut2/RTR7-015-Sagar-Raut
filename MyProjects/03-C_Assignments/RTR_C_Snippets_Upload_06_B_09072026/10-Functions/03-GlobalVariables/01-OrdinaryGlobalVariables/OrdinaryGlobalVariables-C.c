#include <stdio.h>

int SR_global_count = 0;

int main(void)
{

    void SR_change_count_one(void);
    void SR_change_count_two(void);
    void change_count_three(void);

    printf("\n");

    printf("main(): value of SR_global_count = %d\n", SR_global_count);

    SR_change_count_one();
    SR_change_count_two();
    change_count_three();

    printf("\n");

    printf("\n---End---\n");

    return (0);
}

// GLOABL SCOPE
void SR_change_count_one(void)
{
    SR_global_count = 100;
    printf("chnage_count_two() : value of SR_global_count = %d\n", SR_global_count);
}

void SR_change_count_two(void)
{
    SR_global_count = SR_global_count + 1;
    printf("change_count_three() : value of SR_global_count = %d\n", SR_global_count);
}

void change_count_three(void)
{
    SR_global_count = SR_global_count + 10;
    printf("change_count_three() : value of SR_global_count = %d\n", SR_global_count);
}
