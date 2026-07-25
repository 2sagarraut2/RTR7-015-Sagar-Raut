#include <stdio.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_ch;
} MyData;

int main(void)
{
    MyData data;

    printf("\n\n");
    printf("Enter integer value for Data member 'SR_i' of 'struct Myadata' : \n");
    scanf("%d", &data.SR_i);

    printf("Enter float value for Data member 'SR_f' of 'struct Myadata' : \n");
    scanf("%f", &data.SR_f);

    printf("Enter double value for Data member 'SR_d' of 'struct Myadata' : \n");
    scanf("%lf", &data.SR_d);

    printf("Enter character value for Data member 'SR_ch' of 'struct Myadata' : \n");
    scanf(" %c", &data.SR_ch);

    printf("\n\n");
    printf("Data members of 'struct MyData' are:\n\n");
    printf("SR_i = %d\n", data.SR_i);
    printf("SR_f = %f\n", data.SR_f);
    printf("SR_d = %lf\n", data.SR_d);
    printf("SR_ch = %c\n", data.SR_ch);

    printf("\n\n--End--\n\n");
    return (0);
}