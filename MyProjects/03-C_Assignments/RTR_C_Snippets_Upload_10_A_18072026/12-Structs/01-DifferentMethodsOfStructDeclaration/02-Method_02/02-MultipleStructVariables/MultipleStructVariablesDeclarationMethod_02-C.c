#include <stdio.h>

typedef struct
{
    int SR_x;
    int SR_y;
} MyPoint;

MyPoint pointA, pointB, pointC, pointD, pointE;

int main(void)
{

    pointA.SR_x = 2;
    pointA.SR_y = 5;

    pointB.SR_x = 7;
    pointB.SR_y = 1;

    pointC.SR_x = 12;
    pointC.SR_y = 15;

    pointD.SR_x = 9;
    pointD.SR_y = 8;

    pointE.SR_x = 15;
    pointE.SR_y = 25;

    printf("\n\n");
    printf("Co-oridinates (SR_x, SR_y) of point 'A' are (%d, %d) \n\n", pointA.SR_x, pointA.SR_y);
    printf("Co-oridinates (SR_x, SR_y) of point 'A' are (%d, %d) \n\n", pointB.SR_x, pointB.SR_y);
    printf("Co-oridinates (SR_x, SR_y) of point 'A' are (%d, %d) \n\n", pointC.SR_x, pointC.SR_y);
    printf("Co-oridinates (SR_x, SR_y) of point 'A' are (%d, %d) \n\n", pointD.SR_x, pointD.SR_y);
    printf("Co-oridinates (SR_x, SR_y) of point 'A' are (%d, %d) \n\n", pointE.SR_x, pointE.SR_y);

    printf("\n\n--End--\n\n");
    return (0);
}