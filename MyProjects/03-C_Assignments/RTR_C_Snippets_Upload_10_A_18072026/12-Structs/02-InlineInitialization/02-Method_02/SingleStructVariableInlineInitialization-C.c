#include <stdio.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_c;
} MyData;

MyData data = {50, 56.45f, 98.113, 'V'};

int main(void)
{
    printf("\n\n");

    printf("Data members of 'struct MyData' are: \n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("SR_f = %f\n", data.SR_f);
    printf("SR_d = %lf\n", data.SR_d);
    printf("SR_c = %c\n", data.SR_c);

    printf("\n\n--End--\n\n");
    return (0);
}