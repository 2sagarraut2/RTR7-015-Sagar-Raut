#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int i;
    float f;
    double d;
} MyData;

int main(void)
{
    int iSize = 0;
    int fSize = 0;
    int dSize = 0;
    int structMyDataSize = 0;
    int pointerToStructMyDataSize;

    MyData *MyDataPtr;

    MyData *pData = NULL;

    printf("\n\n");

    pData = (MyData *)malloc(sizeof(MyData));

    if (pData == NULL)
    {
        printf("Failed to allocate memory to struct MyData\n\n");
        exit(0);
    }
    else
    {
        printf("Memory successfuly allocated for struct MyData\n\n");
    }

    pData->i = 60;
    pData->f = 5.5f;
    pData->d = 7.7;

    printf("\n\n");
    printf("Data members of struct MyData are\n");
    printf("i = %d\n", pData->i);
    printf("f = %f\n", pData->f);
    printf("d = %lf\n", pData->d);

    iSize = sizeof(pData->i);
    fSize = sizeof(pData->f);
    dSize = sizeof(pData->d);

    printf("Sizes of struct MyData members in bytes are:\n");
    printf("Size of i = %d\n", iSize);
    printf("Size of f = %d\n", fSize);
    printf("Size of d = %d\n", dSize);

    structMyDataSize = sizeof(MyData);
    pointerToStructMyDataSize = sizeof(MyDataPtr);

    printf("Size of 'struct MyData' = %d\n", structMyDataSize);
    printf("Size of pointer to 'struct MyData' = %d\n", pointerToStructMyDataSize);

    if (pData)
    {
        free(pData);
        printf("Memory allocated for pData has been releases!");
        pData = NULL;
    }

    printf("\n\n--End--\n\n");
    return (0);
}