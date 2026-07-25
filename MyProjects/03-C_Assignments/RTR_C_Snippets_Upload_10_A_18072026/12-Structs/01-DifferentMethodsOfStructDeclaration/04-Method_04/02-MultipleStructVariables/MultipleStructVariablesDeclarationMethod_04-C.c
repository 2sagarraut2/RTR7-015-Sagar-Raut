#include <stdio.h>

typedef struct
{
    int SR_x;
    int SR_y;
} MyPoint;

int main(void)
{

    MyPoint pointA, pointB, pointC, pointD, pointE;

    pointA.SR_x = 7;
    pointA.SR_y = 3;

    pointB.SR_x = 45;
    pointB.SR_y = 55;

    pointC.SR_x = 11;
    pointC.SR_y = 22;

    pointD.SR_x = 90;
    pointD.SR_y = 100;

    pointE.SR_x = 134;
    pointE.SR_y = 225;

    printf("\n\n");
    printf("Co-ordinates (SR_x,SR_y) of point 'A' are : (%d, %d)\n\n", pointA.SR_x, pointA.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'B' are : (%d, %d)\n\n", pointB.SR_x, pointB.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'C' are : (%d, %d)\n\n", pointC.SR_x, pointC.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'D' are : (%d, %d)\n\n", pointD.SR_x, pointD.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'E' are : (%d, %d)\n\n", pointE.SR_x, pointE.SR_y);

    printf("\n\n--End--\n\n");
    return (0);
}