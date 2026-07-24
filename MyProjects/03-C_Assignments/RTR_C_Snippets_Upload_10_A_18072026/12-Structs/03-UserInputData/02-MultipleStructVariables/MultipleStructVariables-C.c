#include <stdio.h>

typedef struct
{
    float x;
    float y;
} MyPoint;

int main(void)
{

    MyPoint pointA, pointB, pointC, pointD, pointE;

    printf("\n\n");
    printf("Enter x co-rodinates for point A:\n");
    scanf("%f", &pointA.x);
    printf("Enter y co-rodinates for point A:\n");
    scanf("%f", &pointA.y);

    printf("\n\n");
    printf("Enter x co-rodinates for point B:\n");
    scanf("%f", &pointB.x);
    printf("Enter y co-rodinates for point B:\n");
    scanf("%f", &pointB.y);

    printf("\n\n");
    printf("Enter x co-rodinates for point C:\n");
    scanf("%f", &pointC.x);

    printf("Enter y co-rodinates for point C:\n");
    scanf("%f", &pointC.y);

    printf("\n\n");
    printf("Enter x co-rodinates for point D:\n");
    scanf("%f", &pointD.x);

    printf("Enter y co-rodinates for point D:\n");
    scanf("%f", &pointD.y);

    printf("\n\n");
    printf("Enter x co-rodinates for point E:\n");
    scanf("%f", &pointE.x);

    printf("Enter y co-rodinates for point E:\n");
    scanf("%f", &pointE.y);

    printf("\n\n");
    printf("Co-oridinates (x,y) of point A are: (%f, %f)\n\n", pointA.x, pointA.y);
    printf("Co-oridinates (x,y) of point B are: (%f, %f)\n\n", pointB.x, pointB.y);
    printf("Co-oridinates (x,y) of point C are: (%f, %f)\n\n", pointC.x, pointC.y);
    printf("Co-oridinates (x,y) of point D are: (%f, %f)\n\n", pointD.x, pointD.y);
    printf("Co-oridinates (x,y) of point E are: (%f, %f)\n\n", pointE.x, pointE.y);

    printf("\n\n--End--\n\n");
    return (0);
}