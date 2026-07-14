#include <stdio.h>

int main(void)
{

    int a = 5;

    void SR_change_count(void);

    printf("\n");
    printf("A = %d\n\n", a);

    SR_change_count();

    printf("\n---End---\n");

    return (0);
}

void SR_change_count()
{

    int SR_local_count = 0;

    SR_local_count = SR_local_count + 1;

    printf("SR_local_count = %d", SR_local_count);
}