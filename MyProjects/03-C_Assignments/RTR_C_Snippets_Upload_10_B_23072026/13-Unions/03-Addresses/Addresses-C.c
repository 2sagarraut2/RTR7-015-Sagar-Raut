#include <stdio.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_ch;
} MyStruct;

typedef union
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_ch;
} MyUnion;

int main(void)
{
    MyStruct SR_struct;
    MyUnion SR_union;

    printf("Members of struct are:\n\n");

    SR_struct.SR_i = 34;
    SR_struct.SR_f = 67.56f;
    SR_struct.SR_d = 100.01;
    SR_struct.SR_ch = 'F';

    printf("SR_struct.SR_i = %i\n", SR_struct.SR_i);
    printf("SR_struct.SR_f = %f\n", SR_struct.SR_f);
    printf("SR_struct.SR_d = %lf\n", SR_struct.SR_d);
    printf("SR_struct.SR_ch = %c\n\n", SR_struct.SR_ch);

    printf("Address of Members of struct SR_struct are:\n");
    printf("SR_struct.SR_i = %p\n", &SR_struct.SR_i);
    printf("SR_struct.SR_f = %p\n", &SR_struct.SR_f);
    printf("SR_struct.SR_d = %p\n", &SR_struct.SR_d);
    printf("SR_struct.SR_ch = %p\n", &SR_struct.SR_ch);

    printf("\n\n");
    printf("Members of union SR_union are\n");

    SR_union.SR_i = 10;
    printf("SR_union.SR_i = %i\n\n", SR_union.SR_i);

    SR_union.SR_f = 7.2f;
    printf("SR_union.SR_f = %f\n\n", SR_union.SR_f);

    SR_union.SR_d = 178.3;
    printf("SR_union.SR_d = %lf\n\n", SR_union.SR_d);

    SR_union.SR_ch = 'Z';
    printf("SR_union.SR_ch = %c\n\n", SR_union.SR_ch);

    printf("Address of Members of union SR_union are:\n\n");
    printf("SR_union.SR_i = %p\n", &SR_union.SR_i);
    printf("SR_union.SR_f = %p\n", &SR_union.SR_f);
    printf("SR_union.SR_d = %p\n", &SR_union.SR_d);
    printf("SR_union.SR_ch = %p\n", &SR_union.SR_ch);

    printf("\n\n--End--\n\n");
    return (0);
}