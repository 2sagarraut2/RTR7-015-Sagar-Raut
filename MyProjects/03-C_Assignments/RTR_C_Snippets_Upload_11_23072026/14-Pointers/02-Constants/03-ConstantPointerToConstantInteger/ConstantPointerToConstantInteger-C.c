#include <stdio.h>

int main(void)
{
    int SR_num = 10;
    const int* const ptr = &SR_num;

    printf("\n");
    printf("Current value of SR_num = %d\n", SR_num);
    printf("Current 'ptr' (Address of SR_num) = %p\n", ptr);

    SR_num++;
    printf("\n\n");
    printf("After SR_num++, value of SR_num = %d\n", SR_num);
    printf("Value at this new 'ptr' = %d\n", *ptr);

    printf("\n\n--End--\n\n");
    return (0);
}