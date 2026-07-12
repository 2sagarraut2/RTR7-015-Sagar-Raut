#include <stdio.h>

int global_count = 0;

int main(void)
{

    void change_count_one(void);
    void change_count_two(void);
    void change_count_three(void);

    printf("\n");

    printf("main(): value of global_count = %d\n", global_count);

    change_count_one();
    change_count_two();
    change_count_three();

    printf("\n");

    printf("\n---End---\n");

    return (0);
}

// GLOABL SCOPE
void change_count_one(void)
{
    global_count = 100;
    printf("chnage_count_two() : value of global_count = %d\n", global_count);
}

void change_count_two(void)
{
    global_count = global_count + 1;
    printf("change_count_three() : value of global_count = %d\n", global_count);
}

void change_count_three(void)
{
    global_count = global_count + 10;
    printf("change_count_three() : value of global_count = %d\n", global_count);
}
