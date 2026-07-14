#include <stdio.h>

extern int SR_global_count;

void changeCountOne(void)
{
    SR_global_count = SR_global_count + 1;
    printf("change_count_one() : Value of SR_global_count in File_01 = %d\n", SR_global_count);
}