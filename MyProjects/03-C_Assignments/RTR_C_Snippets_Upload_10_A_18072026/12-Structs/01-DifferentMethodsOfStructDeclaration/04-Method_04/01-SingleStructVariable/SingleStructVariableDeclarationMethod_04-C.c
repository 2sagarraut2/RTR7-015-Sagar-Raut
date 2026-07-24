#include <stdio.h>

typedef struct
{
    int i;
    float f;
    double d;
} MyData;

int main(void)
{
    MyData data;

    int iSize = 0;
    int fSize = 0;
    int dSize = 0;
    int structMyDataSize = 0;

    data.i = 56;
    data.f = 67.5f;
    data.d = 9.6;

    printf("\n\n");
    printf("Data members of 'struct MyData' are : \n\n");
    printf("i = %d\n", data.i);
    printf("i = %f\n", data.f);
    printf("i = %lf\n", data.d);

    iSize = sizeof(data.i);
    fSize = sizeof(data.f);
    dSize = sizeof(data.d);

    printf("\n\n");
    printf("Size of (in bytes) of data members of 'struct MyData' are: \n\n");
    printf("size of i = %d bytes\n", iSize);
    printf("size of i = %d bytes\n", fSize);
    printf("size of i = %d bytes\n", dSize);

    structMyDataSize = sizeof(MyData);

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes\n\n", structMyDataSize);

    printf("\n\n--End--\n\n");
    return (0);
}