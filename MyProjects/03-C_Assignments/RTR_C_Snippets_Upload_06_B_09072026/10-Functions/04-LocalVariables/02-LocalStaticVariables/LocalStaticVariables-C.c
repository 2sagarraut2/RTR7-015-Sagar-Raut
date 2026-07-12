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
    static int local_count = 0;

    local_count = local_count + 1;
    printf("Local count = %d\n\n", local_count);
}