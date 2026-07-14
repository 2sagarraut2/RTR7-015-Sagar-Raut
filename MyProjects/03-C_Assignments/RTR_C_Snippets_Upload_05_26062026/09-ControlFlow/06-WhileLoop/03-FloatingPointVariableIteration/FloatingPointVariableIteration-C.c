#include <stdio.h>

int main(void)
{

    float f;
    float SR_f_num = 1.7f;

    printf("\n");

    printf("printing numbers from %f to %f : \n\n", SR_f_num, (SR_f_num * 10.0f));

    f = SR_f_num;

    while (f <= (SR_f_num * 10.0f))
    {
        printf("\t %f\n", f);
        f = f + SR_f_num;
    }

    printf("\n\n");

    return 0;
}