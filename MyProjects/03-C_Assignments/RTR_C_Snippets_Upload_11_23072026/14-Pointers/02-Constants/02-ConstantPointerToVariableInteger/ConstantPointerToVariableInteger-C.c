#include <stdio.h>

int main(void)
{
    int SR_num = 6;
    int* const ptr = &SR_num;

    printf("\n");
    printf("Current value of SR_num = %d\n", SR_num);
    printf("Current 'ptr' (Address of SR_num) = %p\n", ptr);

    SR_num++;
    printf("\n\n");
    printf("After SR_num++, value of SR_num = %d\n", SR_num);
    printf("Value at this new 'ptr' = %d\n", *ptr);

    (*ptr)++;

    printf("\n\n");
    printf("After ptr++, value of 'ptr' = %p\n", ptr);
    printf("Value at this new 'ptr' = %d\n", *ptr);
    printf("\n");

    printf("\n\n--End--\n\n");
    return (0);
}