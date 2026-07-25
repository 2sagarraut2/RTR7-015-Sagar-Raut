#include <stdio.h>

typedef union
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_ch;
} MyUnion;

int main(void)
{
    MyUnion SR_union1, SR_union2;

    printf("\n\n");
    printf("Members of union1 are\n");

    SR_union1.SR_i = 8;
    SR_union1.SR_f = 4.5f;
    SR_union1.SR_d = 4.4;
    SR_union1.SR_ch = 'A';

    printf("SR_union1.SR_i = %i\n", SR_union1.SR_i);
    printf("SR_union1.SR_f = %f\n", SR_union1.SR_f);
    printf("SR_union1.SR_d = %lf\n", SR_union1.SR_d);
    printf("SR_union1.SR_ch = %c\n", SR_union1.SR_ch);

    printf("Address of Members of union SR_union1 are:\n\n");
    printf("SR_union1.SR_i = %i\n", SR_union1.SR_i);
    printf("SR_union1.SR_f = %f\n", SR_union1.SR_f);
    printf("SR_union1.SR_d = %lf\n", SR_union1.SR_d);
    printf("SR_union1.SR_ch = %c\n", SR_union1.SR_ch);

    printf("MyUnion SR_union1 = %p\n\n", &SR_union1);

    printf("\n\n");
    printf("Members of union2 are\n");

    SR_union2.SR_i = 8;
    printf("SR_union2.SR_i = %i\n\n", SR_union2.SR_i);

    SR_union2.SR_f = 4.5f;
    printf("SR_union2.SR_f = %f\n\n", SR_union2.SR_f);

    SR_union2.SR_d = 4.4;
    printf("SR_union2.SR_d = %lf\n\n", SR_union2.SR_d);

    SR_union2.SR_ch = 'A';
    printf("SR_union2.SR_ch = %c\n\n", SR_union2.SR_ch);

    printf("Address of Members of union SR_union1 are:\n\n");
    printf("SR_union1.SR_i = %p\n", &SR_union2.SR_i);
    printf("SR_union1.SR_f = %p\n", &SR_union2.SR_f);
    printf("SR_union1.SR_d = %p\n", &SR_union2.SR_d);
    printf("SR_union1.SR_ch = %p\n", &SR_union2.SR_ch);

    printf("MyUnion SR_union2 = %p\n\n", &SR_union2);

    printf("\n\n--End--\n\n");
    return (0);
}