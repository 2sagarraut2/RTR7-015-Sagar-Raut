#include <stdio.h>

int main(void)
{
    double SR_num;
    double *dptr = NULL;

    SR_num = 2.22;

    printf("\n\n");

    printf("*** Before pointer assignment ***\n\n");

    printf("Value of num %f\n", SR_num);
    printf("Address of num %p\n", &SR_num);
    printf("Value at address of num %f\n", *(&SR_num));
    printf("Address of *dptr %p\n\n", &dptr);

    dptr = &SR_num;

    printf("*** After pointer assignment ***\n\n");
    printf("Value of num %f\n", *(&SR_num));
    printf("Address of num %p\n", dptr);
    printf("Value at address of num %f\n", *(dptr));
    printf("Address of *dptr %p\n\n", &dptr);

    printf("\n\n--End--\n\n");
    return (0);
}