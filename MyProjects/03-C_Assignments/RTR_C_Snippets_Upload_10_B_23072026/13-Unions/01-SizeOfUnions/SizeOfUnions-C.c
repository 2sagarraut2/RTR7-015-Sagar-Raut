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
    MyStruct SR_stuct;
    MyUnion SR_union;

    printf("\n\n");
    printf("Size of MyStruct = %lu\n", sizeof(SR_stuct));
    printf("Size of MyUnion = %lu\n", sizeof(SR_union));

    printf("\n\n--End--\n\n");
    return (0);
}