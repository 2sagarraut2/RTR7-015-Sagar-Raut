#include <stdio.h>

int main(void)
{

    void change_count(void);

    extern int global_count;

    printf("\n");
    printf("Value of global_count before change_count() = %d\n", global_count);
    change_count();
    printf("Value of global_count after change_count() = %d\n", global_count);
    printf("\n");

    printf("\n---End---\n");

    return (0);
}

int global_count = 0;

void change_count(void)
{
    global_count = 5;

    printf("Value of global_count in change_count() %d\n", global_count);
    global_count = global_count + 5;
}