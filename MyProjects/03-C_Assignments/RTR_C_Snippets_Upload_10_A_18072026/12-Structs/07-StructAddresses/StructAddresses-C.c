#include <stdio.h>

struct MyData
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    struct MyData data;

    data.i = 40;
    data.f = 11.56f;
    data.d = 45.666;
    data.c = 'S';

    printf("\n\n");
    printf("Struct members of MyData are \n\n");
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("d = %lf\n", data.d);
    printf("c = %c\n", data.c);

    printf("\n\n");
    printf("Address of data members of struct\n\n");
    printf("i = %p\n", &data.i);
    printf("f = %p\n", &data.f);
    printf("d = %p\n", &data.d);
    printf("c = %p\n", &data.c);

    printf("starting address of struct MyData variable 'data' is %p\n\n", &data);

    printf("\n\n--End--\n\n");
    return (0);
}