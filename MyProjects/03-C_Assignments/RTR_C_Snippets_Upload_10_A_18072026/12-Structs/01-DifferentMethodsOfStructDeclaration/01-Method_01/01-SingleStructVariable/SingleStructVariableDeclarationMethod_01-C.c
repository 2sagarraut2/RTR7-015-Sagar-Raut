#include <stdio.h>

typedef struct
{
    int i;
    float f;
    double d;
    char c;
} MyData;

MyData data;

int main(void)
{
    int iSize = 0, fSize = 0, dSize = 0, structMyDataSize = 0;

    data.i = 30;
    data.f = 2.5f;
    data.d = 3.0;

    printf("\n\n");
    printf("Data memebers of of 'struct MyData' are :\n\n");
    printf("i = %d\n", data.i);
    printf("i = %f\n", data.f);
    printf("i = %lf\n", data.d);

    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);

    printf("\n\n");
    printf("Sizes of data (in bytes) members of struct MyData are: \n\n");
    printf("Size of i = %d bytes\n", iSize);
    printf("Size of f = %d bytes\n", fSize);
    printf("Size of d = %d bytes\n", dSize);

    structMyDataSize = sizeof(MyData);

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes \n\n", structMyDataSize);

    printf("\n\n--End--\n\n");
    return (0);
}