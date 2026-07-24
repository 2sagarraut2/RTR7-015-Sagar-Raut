#include <stdio.h>

int main(void)
{
    float SR_num;
    float *fptr = NULL;

    SR_num = 5.6f;

    printf("\n\n");

    printf("*** Before pointer assignment ***\n\n");

    printf("Value of num %f\n", SR_num);
    printf("Address of num %p\n", &SR_num);
    printf("Value at address of num %f\n", *(&SR_num));
    printf("Address of *fptr %p\n\n", &fptr);

    fptr = &SR_num;

    printf("*** After pointer assignment ***\n\n");
    printf("Value of num %f\n", *(&SR_num));
    printf("Address of num %p\n", fptr);
    printf("Value at address of num %f\n", *(fptr));

    printf("\n\n--End--\n\n");
    return (0);
}