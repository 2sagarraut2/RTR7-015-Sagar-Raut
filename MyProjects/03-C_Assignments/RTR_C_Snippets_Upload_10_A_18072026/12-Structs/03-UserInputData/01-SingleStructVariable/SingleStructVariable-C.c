#include <stdio.h>

typedef struct
{
    int i;
    float f;
    double d;
    char ch;
} MyData;

int main(void)
{
    MyData data;

    printf("\n\n");
    printf("Enter integer value for Data member 'i' of 'struct Myadata' : \n");
    scanf("%d", &data.i);

    printf("Enter float value for Data member 'f' of 'struct Myadata' : \n");
    scanf("%f", &data.f);

    printf("Enter double value for Data member 'f' of 'struct Myadata' : \n");
    scanf("%lf", &data.d);

    printf("Enter character value for Data member 'd' of 'struct Myadata' : \n");
    scanf(" %c", &data.ch);

    printf("\n\n");
    printf("Data members of 'struct MyData' are:\n\n");
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("f = %lf\n", data.f);
    printf("ch = %c\n", data.ch);

    printf("\n\n--End--\n\n");
    return (0);
}