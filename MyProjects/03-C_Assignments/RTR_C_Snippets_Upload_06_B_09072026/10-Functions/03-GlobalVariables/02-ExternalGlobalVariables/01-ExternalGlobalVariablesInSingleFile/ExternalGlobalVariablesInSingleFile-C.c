#include <stdio.h>

int main(void)
{

    void SR_change_count(void);

    extern int SR_global_count;

    printf("\n");
    printf("Value of SR_global_count before SR_change_count() = %d\n", SR_global_count);
    SR_change_count();
    printf("Value of SR_global_count after SR_change_count() = %d\n", SR_global_count);
    printf("\n");

    printf("\n---End---\n");

    return (0);
}

int SR_global_count = 0;

void SR_change_count(void)
{
    SR_global_count = 5;

    printf("Value of SR_global_count in SR_change_count() %d\n", SR_global_count);
    SR_global_count = SR_global_count + 5;
}