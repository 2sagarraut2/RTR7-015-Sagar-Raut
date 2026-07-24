#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int SR_i;
        float SR_f;
        double SR_d;
        char SR_c;
    } MyData;

    MyData SR_data = {100, 67.87f, 67.789, 'V'};

    printf("\n\n");

    printf("Data members of 'struct MyData' are: \n\n");
    printf("SR_i = %d\n", SR_data.SR_i);
    printf("SR_f = %f\n", SR_data.SR_f);
    printf("SR_d = %lf\n", SR_data.SR_d);
    printf("SR_c = %c\n", SR_data.SR_c);

    printf("\n\n--End--\n\n");
    return (0);
}