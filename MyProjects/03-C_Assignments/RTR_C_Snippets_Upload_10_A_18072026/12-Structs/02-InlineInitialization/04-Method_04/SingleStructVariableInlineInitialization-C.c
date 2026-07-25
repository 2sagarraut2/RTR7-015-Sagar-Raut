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
    MyData dataOne = {55, 44.44f, 345.6, 'F'};

    MyData dataTwo = {66, 55.44f, 123.6, 'R'};

    MyData dataThree = {77, 66.44f, 789.6, 'G'};

    MyData dataFour = {88, 77.44f, 345.6, 'S'};

    printf("\n\n");
    printf("Data members of 'struct MyData dataOne' are: \n");
    printf("SR_i = %d\n", dataOne.SR_i);
    printf("SR_f = %f\n", dataOne.SR_f);
    printf("SR_d = %lf\n", dataOne.SR_d);
    printf("SR_ch = %ch\n", dataOne.SR_ch);

    printf("\n\n");
    printf("Data members of 'struct MyData dataTwo' are: \n");
    printf("SR_i = %d\n", dataTwo.SR_i);
    printf("SR_f = %f\n", dataTwo.SR_f);
    printf("SR_d = %lf\n", dataTwo.SR_d);
    printf("SR_ch = %ch\n", dataTwo.SR_ch);

    printf("\n\n");
    printf("Data members of 'struct MyData dataThree' are: \n");
    printf("SR_i = %d\n", dataThree.SR_i);
    printf("SR_f = %f\n", dataThree.SR_f);
    printf("SR_d = %lf\n", dataThree.SR_d);
    printf("SR_ch = %ch\n", dataThree.SR_ch);

    printf("\n\n");
    printf("Data members of 'struct MyData dataFour' are: \n");
    printf("SR_i = %d\n", dataFour.SR_i);
    printf("SR_f = %f\n", dataFour.SR_f);
    printf("SR_d = %lf\n", dataFour.SR_d);
    printf("SR_ch = %ch\n", dataFour.SR_ch);

    printf("\n\n--End--\n\n");
    return (0);
}