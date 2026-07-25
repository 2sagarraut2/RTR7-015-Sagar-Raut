#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int SR_i;
        float SR_f;
        double SR_d;
    } MyData;

    MyData data;

    int iSize = 0, fSize = 0, dSize = 0, MyDataSize = 0;

    data.SR_i = 50;
    data.SR_f = 2.3f;
    data.SR_d = 5.577;

    printf("\n\n");
    printf("Data members of 'struct MyData' are: \n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("SR_f = %f\n", data.SR_f);
    printf("SR_d = %lf\n", data.SR_d);

    MyDataSize = sizeof(MyData);

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes \n\n", MyDataSize);

    printf("\n\n--End--\n\n");
    return (0);
}