#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int i;
        float f;
        double d;
    } MyData;

    MyData data;

    int iSize = 0, fSize = 0, dSize = 0, MyDataSize = 0;

    data.i = 50;
    data.f = 2.3f;
    data.d = 5.577;

    printf("\n\n");
    printf("Data members of 'struct MyData' are: \n\n");
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("d = %lf\n", data.d);

    MyDataSize = sizeof(MyData);

    printf("\n\n");
    printf("Size of 'struct MyData' : %d bytes \n\n", MyDataSize);

    printf("\n\n--End--\n\n");
    return (0);
}