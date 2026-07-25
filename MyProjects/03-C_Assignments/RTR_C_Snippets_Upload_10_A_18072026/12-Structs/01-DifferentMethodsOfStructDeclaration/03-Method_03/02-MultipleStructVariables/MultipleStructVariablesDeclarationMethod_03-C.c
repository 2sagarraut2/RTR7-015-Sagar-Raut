#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int SR_x;
        int SR_y;
    } MyPoint;

    MyPoint pointA, pointB, pointC, pointD, pointE;

    pointA.SR_x = 6;
    pointA.SR_y = 9;

    pointB.SR_x = 1;
    pointB.SR_y = 0;

    pointC.SR_x = 11;
    pointC.SR_y = 57;

    pointD.SR_x = 45;
    pointD.SR_y = 67;

    pointE.SR_x = 78;
    pointE.SR_y = 45;

    printf("\n\n");
    printf("Co-ordinates (SR_x,SR_y) of point 'A' are : (%d, %d)\n\n", pointA.SR_x, pointA.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'B' are : (%d, %d)\n\n", pointB.SR_x, pointB.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'C' are : (%d, %d)\n\n", pointC.SR_x, pointC.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'D' are : (%d, %d)\n\n", pointD.SR_x, pointD.SR_y);
    printf("Co-ordinates (SR_x,SR_y) of point 'E' are : (%d, %d)\n\n", pointE.SR_x, pointE.SR_y);

    printf("\n\n--End--\n\n");
    return (0);
}