#include <stdio.h>

union MyData
{
    int i;
    float f;
    double d;
    char c;
};

union MyData U_data;

int main(void)
{
    printf("size of union is %lu\n", sizeof(U_data));

    U_data.i = 10;
    printf("%d\n", U_data.i);
    printf("%p\n", &U_data.i);
    U_data.f = 2.5f;
    printf("%f\n", U_data.f);
    printf("%p\n", &U_data.f);
    U_data.d = 3.5;
    printf("%lf\n", U_data.d);
    printf("%p\n", &U_data.d);
    U_data.c = 'a';
    printf("%c\n", U_data.c);
    printf("%p\n", &U_data.c);

    printf("size of integer pointer is %lu\n", sizeof(int *));
    printf("size of double pointer is %lu\n", sizeof(double *));
    printf("size of character pointer is %lu\n", sizeof(char *));

    printf("\n\n--End--\n\n");
    return (0);
}