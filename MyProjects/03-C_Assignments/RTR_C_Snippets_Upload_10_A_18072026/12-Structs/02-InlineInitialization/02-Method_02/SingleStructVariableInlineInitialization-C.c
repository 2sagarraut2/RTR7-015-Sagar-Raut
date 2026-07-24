#include <stdio.h>

typedef struct
{
    int i;
    float f;
    double d;
    char c;
} MyData;

MyData data = {50, 56.45f, 98.113, 'V'};

int main(void)
{
    printf("\n\n");

    printf("Data members of 'struct MyData' are: \n\n");
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("d = %lf\n", data.d);
    printf("c = %c\n", data.c);

    printf("\n\n--End--\n\n");
    return (0);
}