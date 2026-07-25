#include <stdio.h>

typedef struct
{
    int SR_x;
    int SR_y;
} MyPoint;

MyPoint pointA, pointB, pointC, pointD, pointE;

int main(void)
{
    pointA.SR_x = 4;
    pointA.SR_y = 2;

    pointB.SR_x = 5;
    pointB.SR_y = 6;

    pointC.SR_x = 6;
    pointC.SR_y = 8;

    pointD.SR_x = 9;
    pointD.SR_y = 5;

    pointE.SR_x = 11;
    pointE.SR_y = 12;

    printf("\n\n");
    printf("Co-ordinates (SR_x,SR_y) of point 'A' are : (%d, %d)\n\n", pointA.SR_x, pointA.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'B' are : (%d, %d)\n\n", pointB.SR_x, pointB.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'C' are : (%d, %d)\n\n", pointC.SR_x, pointC.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'D' are : (%d, %d)\n\n", pointD.SR_x, pointD.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'E' are : (%d, %d)\n\n", pointE.SR_x, pointE.SR_y);

    printf("\n\n--End--\n\n");
    return (0);
}