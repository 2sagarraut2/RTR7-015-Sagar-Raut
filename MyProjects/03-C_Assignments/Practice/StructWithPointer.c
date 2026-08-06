#include <stdio.h>

typedef struct
{
    int i;
    float f;
    char c;
    double d;
} MyData;

int main(void)
{
    int Addition(int, int);

    MyData data;

    data.i = 10;
    data.f = 3.4f;
    data.d = 5.5;
    data.c = 'P';

    MyData *ptrData = NULL;
    ptrData = &data;

    printf("%d\n", ptrData->i);
    printf("%d\n", (*ptrData).i);
    printf("%f\n", ptrData->f);
    printf("%f\n", (*ptrData).f);
    printf("%lf\n", ptrData->d);
    printf("%lf\n", (*ptrData).d);
    printf("%c\n", ptrData->c);
    printf("%c\n", (*ptrData).c);

    printf("\n\n--End--\n\n");

    int a = 20, b = 100;
    int result = 0;

    result = Addition(a, b);

    printf("Addition is %d\n", result);

    return (0);
}