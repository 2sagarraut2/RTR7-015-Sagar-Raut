#include <stdio.h>

int main(void)
{

    int a = 5;

    void change_count(void);

    printf("\n");
    printf("A = %d\n\n", a);

    change_count();

    printf("\n---End---\n");

    return (0);
}

void change_count()
{

    int local_count = 0;

    local_count = local_count + 1;

    printf("local_count = %d", local_count);
}