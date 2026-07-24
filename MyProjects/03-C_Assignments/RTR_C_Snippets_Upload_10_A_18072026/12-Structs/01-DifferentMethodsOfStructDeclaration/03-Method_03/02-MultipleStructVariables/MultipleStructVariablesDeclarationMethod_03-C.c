#include <stdio.h>

int main(void)
{
    typedef struct
    {
        int x;
        int y;
    } MyPoint;

    MyPoint pointA, pointB, pointC, pointD, pointE;

    pointA.x = 6;
    pointA.y = 9;

    pointB.x = 1;
    pointB.y = 0;

    pointC.x = 11;
    pointC.y = 57;

    pointD.x = 45;
    pointD.y = 67;

    pointE.x = 78;
    pointE.y = 45;

    printf("\n\n");
    printf("Co-ordinates (x,y) of point 'A' are : (%d, %d)\n\n", pointA.x, pointA.y);
    printf("Co-ordinates (x,y) of point 'B' are : (%d, %d)\n\n", pointB.x, pointB.y);
    printf("Co-ordinates (x,y) of point 'C' are : (%d, %d)\n\n", pointC.x, pointC.y);
    printf("Co-ordinates (x,y) of point 'D' are : (%d, %d)\n\n", pointD.x, pointD.y);
    printf("Co-ordinates (x,y) of point 'E' are : (%d, %d)\n\n", pointE.x, pointE.y);

    printf("\n\n--End--\n\n");
    return (0);
}