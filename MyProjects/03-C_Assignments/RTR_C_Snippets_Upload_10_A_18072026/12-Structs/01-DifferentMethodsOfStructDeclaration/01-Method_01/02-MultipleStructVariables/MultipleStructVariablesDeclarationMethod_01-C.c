#include <stdio.h>

typedef struct
{
    int x;
    int y;
} MyPoint;

MyPoint pointA, pointB, pointC, pointD, pointE;

int main(void)
{
    pointA.x = 4;
    pointA.y = 2;

    pointB.x = 5;
    pointB.y = 6;

    pointC.x = 6;
    pointC.y = 8;

    pointD.x = 9;
    pointD.y = 5;

    pointE.x = 11;
    pointE.y = 12;

    printf("\n\n");
    printf("Co-ordinates (x,y) of point 'A' are : (%d, %d)\n\n", pointA.x, pointA.y);
    printf("Co-ordinates (x,y) of point 'B' are : (%d, %d)\n\n", pointB.x, pointB.y);
    printf("Co-ordinates (x,y) of point 'C' are : (%d, %d)\n\n", pointC.x, pointC.y);
    printf("Co-ordinates (x,y) of point 'D' are : (%d, %d)\n\n", pointD.x, pointD.y);
    printf("Co-ordinates (x,y) of point 'E' are : (%d, %d)\n\n", pointE.x, pointE.y);

    printf("\n\n--End--\n\n");
    return (0);
}