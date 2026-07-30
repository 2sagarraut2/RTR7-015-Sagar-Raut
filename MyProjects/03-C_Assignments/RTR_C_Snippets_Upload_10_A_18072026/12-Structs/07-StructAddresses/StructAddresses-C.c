#include <stdio.h>

struct MyData
{
    int SR_i;
    float f;
    double d;
    char c;
};

int main(void)
{
    struct MyData data;

    data.SR_i = 40;
    data.f = 11.56f;
    data.d = 45.666;
    data.c = 'S';

    printf("\n\n");
    printf("Struct members of MyData are \n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("f = %f\n", data.f);
    printf("d = %lf\n", data.d);
    printf("c = %c\n", data.c);

    printf("\n\n");
    printf("Address of data members of struct\n\n");
    printf("SR_i = %p\n", &data.SR_i);
    printf("f = %p\n", &data.f);
    printf("d = %p\n", &data.d);
    printf("c = %p\n", &data.c);

    printf("starting address of struct MyData variable 'data' is %p\n\n", &data);

    printf("\n\n--End--\n\n");
    return (0);
}