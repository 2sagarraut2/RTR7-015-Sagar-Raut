#include <stdio.h>

typedef struct
{
    int x;
    int y;
} MyPoint;

MyPoint pointA, pointB, pointC, pointD, pointE;

int main(void)
{

    pointA.x = 2;
    pointA.y = 5;

    pointB.x = 7;
    pointB.y = 1;

    pointC.x = 12;
    pointC.y = 15;

    pointD.x = 9;
    pointD.y = 8;

    pointE.x = 15;
    pointE.y = 25;

    printf("\n\n");
    printf("Co-oridinates (x, y) of point 'A' are (%d, %d) \n\n", pointA.x, pointA.y);
    printf("Co-oridinates (x, y) of point 'A' are (%d, %d) \n\n", pointB.x, pointB.y);
    printf("Co-oridinates (x, y) of point 'A' are (%d, %d) \n\n", pointC.x, pointC.y);
    printf("Co-oridinates (x, y) of point 'A' are (%d, %d) \n\n", pointD.x, pointD.y);
    printf("Co-oridinates (x, y) of point 'A' are (%d, %d) \n\n", pointE.x, pointE.y);

    printf("\n\n--End--\n\n");
    return (0);
}