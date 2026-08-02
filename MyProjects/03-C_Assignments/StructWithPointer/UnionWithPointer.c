#include <stdio.h>

typedef union
{
    int i;
    float f;
    char c;
    double d;
} MyData;

int main(void)
{

    MyData data;
    MyData *ptrData = NULL;
    ptrData = &data;

    data.i = 20;
    printf("%d\n", ptrData->i);
    printf("%d\n", (*ptrData).i);
    data.f = 5.6f;
    printf("%f\n", ptrData->f);
    printf("%f\n", (*ptrData).f);
    data.d = 2.2;
    printf("%lf\n", ptrData->d);
    printf("%lf\n", (*ptrData).d);
    data.c = 'J';
    printf("%c\n", ptrData->c);
    printf("%c\n", (*ptrData).c);

    printf("\n\n--End--\n\n");
    return (0);
}