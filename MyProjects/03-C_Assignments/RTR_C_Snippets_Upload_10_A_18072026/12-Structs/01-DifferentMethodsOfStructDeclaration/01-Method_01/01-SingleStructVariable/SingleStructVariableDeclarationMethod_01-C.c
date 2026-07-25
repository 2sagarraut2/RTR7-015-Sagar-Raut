#include <stdio.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_c;
} MyData;

MyData data;

int main(void)
{
    int iSize = 0, fSize = 0, dSize = 0, structMyDataSize = 0;

    data.SR_i = 30;
    data.SR_f = 2.5f;
    data.SR_d = 3.0;

    printf("\n\n");
    printf("Data memebers of of 'struct MyData' are :\n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("SR_f = %f\n", data.SR_f);
    printf("SR_d = %lf\n", data.SR_d);

    iSize = sizeof(data.SR_i);
    fSize = sizeof(data.SR_f);
    dSize = sizeof(data.SR_d);

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