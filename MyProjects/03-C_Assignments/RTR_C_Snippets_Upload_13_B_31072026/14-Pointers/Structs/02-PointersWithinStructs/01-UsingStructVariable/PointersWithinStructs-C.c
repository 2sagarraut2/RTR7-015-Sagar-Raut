#include <stdio.h>

typedef struct
{
    int *SR_iPtr;
    int i;

    float *SR_fPtr;
    float f;

    double *SR_dPtr;
    double d;
} MyData;

int main(void)
{
    MyData SR_data;

    SR_data.i = 9;
    SR_data.SR_iPtr = (&SR_data.i);

    SR_data.f = 5.5f;
    SR_data.SR_fPtr = (&SR_data.f);

    SR_data.d = 8.8;
    SR_data.SR_dPtr = (&SR_data.d);

    printf("\n\n");
    printf("i = %d\n", *(SR_data.SR_iPtr));
    printf("Address of i = %p\n", SR_data.SR_iPtr);

    printf("\n\n");
    printf("f = %f\n", *(SR_data.SR_fPtr));
    printf("Address of f = %p\n", SR_data.SR_fPtr);

    printf("\n\n");
    printf("d = %lf\n", *(SR_data.SR_dPtr));
    printf("Address of d = %p\n", SR_data.SR_dPtr);

    printf("\n\n--End--\n\n");
    return (0);
}