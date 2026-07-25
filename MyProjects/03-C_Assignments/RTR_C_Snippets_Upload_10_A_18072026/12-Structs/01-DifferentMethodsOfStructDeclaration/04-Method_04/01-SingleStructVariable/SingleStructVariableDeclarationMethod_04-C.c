#include <stdio.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
} MyData;

int main(void)
{
    MyData data;

    int iSize = 0;
    int fSize = 0;
    int dSize = 0;
    int structMyDataSize = 0;

    data.SR_i = 56;
    data.SR_f = 67.5f;
    data.SR_d = 9.6;

    printf("\n\n");
    printf("Data members of 'struct MyData' are : \n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("SR_f = %f\n", data.SR_f);
    printf("SR_d = %lf\n", data.SR_d);

    iSize = sizeof(data.SR_i);
    fSize = sizeof(data.SR_f);
    dSize = sizeof(data.SR_d);

    printf("\n\n");
    printf("Size of (in bytes) of data members of 'struct MyData' are: \n\n");
    printf("size of SR_i = %d bytes\n", iSize);
    printf("size of SR_f = %d bytes\n", fSize);
    printf("size of SR_d = %d bytes\n", dSize);

    structMyDataSize = sizeof(MyData);

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes\n\n", structMyDataSize);

    printf("\n\n--End--\n\n");
    return (0);
}