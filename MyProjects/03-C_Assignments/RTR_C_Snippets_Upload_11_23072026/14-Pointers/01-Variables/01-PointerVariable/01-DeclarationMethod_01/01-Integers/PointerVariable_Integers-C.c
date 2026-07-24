#include <stdio.h>

int main(void)
{
    int SR_num;
    int *ptr = NULL;

    SR_num = 10;

    printf("--- Before assigning to pointer ----\n\n");
    printf("Value of SR_num = %d\n", SR_num);
    printf("Address of SR_num = %p\n", &SR_num);
    printf("Value at address of SR_num = %d\n", *(&SR_num));

    printf("Address of pointer = %p\n", ptr);
    // printf("Value at address of SR_num = %d\n", *ptr);

    ptr = &SR_num;

    printf("\n\n");

    printf("After assigning to pointer");
    printf("Value of SR_num = %d\n", SR_num);
    printf("Address of SR_num = %p\n", ptr);
    printf("Value at address of SR_num = %d\n", *ptr);

    printf("\n\n--End--\n\n");
    return (0);
}