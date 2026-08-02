#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
} MyData;

int main(void)
{

    int SR_iSize = 0;
    int SR_fSize = 0;
    int SR_dSize = 0;
    int SR_StructMyDataSize = 0;
    int SR_PointerToStructMyDataSize = 0;

    MyData *SR_pData = NULL;

    printf("\n\n");

    SR_pData = (MyData *)malloc(sizeof(MyData));
    if (SR_pData == NULL)
    {
        printf("failed to allocated memory for structure\n");
        exit(0);
    }
    else
    {
        printf("Memory allocation was successful\n\n");
    }

    SR_pData->SR_i = 10;
    SR_pData->SR_f = 10.5f;
    SR_pData->SR_d = 2.4;

    printf("\n\n");
    printf("Data members of struct MyData are:\n\n");
    printf("SR_i = %d\n", SR_pData->SR_i);
    printf("SR_f = %f\n", SR_pData->SR_f);
    printf("SR_d = %lf\n", SR_pData->SR_d);

    SR_iSize = sizeof(SR_pData->SR_i);
    SR_fSize = sizeof(SR_pData->SR_f);
    SR_dSize = sizeof(SR_pData->SR_d);

    printf("Sizes of data members of Struct MyData are : \n\n");
    printf("Size of SR_i = %d bytes\n", SR_iSize);
    printf("Size of SR_f = %d bytes\n", SR_fSize);
    printf("Size of SR_d = %d bytes\n", SR_dSize);

    SR_StructMyDataSize = sizeof(MyData);
    SR_PointerToStructMyDataSize = sizeof(MyData *);

    printf("\n\n");
    printf("Size of 'struct MyData' is %d bytes\n", SR_StructMyDataSize);
    printf("Size of 'struct MyData Pointer' is %d bytes\n\n", SR_PointerToStructMyDataSize);

    if (SR_pData)
    {
        free(SR_pData);
        SR_pData = NULL;
        printf("Memory allocated for 'struct MyData' has been released!");
    }

    printf("\n\n--End--\n\n");
    return (0);
}