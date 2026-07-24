#include <stdio.h>

typedef struct
{
    int i;
    float f;
    double d;
    char c;
} MyData;

int main(void)
{
    MyData dataOne = {55, 44.44f, 345.6, 'F'};

    MyData dataTwo = {66, 55.44f, 123.6, 'R'};

    MyData dataThree = {77, 66.44f, 789.6, 'G'};

    MyData dataFour = {88, 77.44f, 345.6, 'S'};

    printf("\n\n");
    printf("Data members of 'struct MyData dataOne' are: \n");
    printf("i = %d\n", dataOne.i);
    printf("i = %f\n", dataOne.f);
    printf("i = %lf\n", dataOne.d);
    printf("i = %c\n", dataOne.c);

    printf("\n\n");
    printf("Data members of 'struct MyData dataTwo' are: \n");
    printf("i = %d\n", dataTwo.i);
    printf("i = %f\n", dataTwo.f);
    printf("i = %lf\n", dataTwo.d);
    printf("i = %c\n", dataTwo.c);

    printf("\n\n");
    printf("Data members of 'struct MyData dataThree' are: \n");
    printf("i = %d\n", dataThree.i);
    printf("i = %f\n", dataThree.f);
    printf("i = %lf\n", dataThree.d);
    printf("i = %c\n", dataThree.c);

    printf("\n\n");
    printf("Data members of 'struct MyData dataFour' are: \n");
    printf("i = %d\n", dataFour.i);
    printf("i = %f\n", dataFour.f);
    printf("i = %lf\n", dataFour.d);
    printf("i = %c\n", dataFour.c);

    printf("\n\n--End--\n\n");
    return (0);
}