#include <stdio.h>
#include <stdlib.h>

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
    MyData *SR_Data = NULL;

    printf("\n\n");
    SR_Data = (MyData *)malloc(sizeof(MyData));
    if (SR_Data == NULL)
    {
        printf("Memory allocation failed\n");
    }
    else
    {
        printf("Memory allocated successfully");
    }

    (*SR_Data).i = 9;
    (*SR_Data).SR_iPtr = &(*SR_Data).i;

    (*SR_Data).f = 5.5f;
    (*SR_Data).SR_fPtr = &(*SR_Data).f;

    (*SR_Data).d = 8.8;
    (*SR_Data).SR_dPtr = &(*SR_Data).d;

    printf("\n\n");
    printf("i = %d\n", *(*SR_Data).SR_iPtr);
    printf("Address of i = %p\n", (*SR_Data).SR_iPtr);

    printf("\n\n");
    printf("f = %f\n", *(*SR_Data).SR_fPtr);
    printf("Address of f = %p\n", (*SR_Data).SR_fPtr);

    printf("\n\n");
    printf("d = %lf\n", *(*SR_Data).SR_dPtr);
    printf("Address of d = %p\n", (*SR_Data).SR_dPtr);

    if (SR_Data)
    {
        free(SR_Data);
        SR_Data = NULL;
        printf("Allocated memory has been released");
    }

    printf("\n\n--End--\n\n");
    return (0);
}