#include <stdio.h>

typedef struct
{
    int x;
    int y;
} MyPoint;

int main(void)
{

    MyPoint pointA, pointB, pointC, pointD, pointE;

    pointA.x = 7;
    pointA.y = 3;

    pointB.x = 45;
    pointB.y = 55;

    pointC.x = 11;
    pointC.y = 22;

    pointD.x = 90;
    pointD.y = 100;

    pointE.x = 134;
    pointE.y = 225;

    printf("\n\n");
    printf("Co-ordinates (x,y) of point 'A' are : (%d, %d)\n\n", pointA.x, pointA.y);
    printf("Co-ordinates (x,y) of point 'B' are : (%d, %d)\n\n", pointB.x, pointB.y);
    printf("Co-ordinates (x,y) of point 'C' are : (%d, %d)\n\n", pointC.x, pointC.y);
    printf("Co-ordinates (x,y) of point 'D' are : (%d, %d)\n\n", pointD.x, pointD.y);
    printf("Co-ordinates (x,y) of point 'E' are : (%d, %d)\n\n", pointE.x, pointE.y);

    printf("\n\n--End--\n\n");
    return (0);
}