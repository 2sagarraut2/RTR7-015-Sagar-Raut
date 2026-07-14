#include <stdio.h>

void changeCountTwo(void)
{
    extern int SR_global_count;

    SR_global_count = SR_global_count + 1;
    printf("change_count_two() : Value of SR_global_count in File_02 = %d\n", SR_global_count);
}