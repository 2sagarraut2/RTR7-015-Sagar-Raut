#include <stdio.h>

typedef struct
{
    float SR_x;
    float SR_y;
} MyPoint;

int main(void)
{

    MyPoint pointA, pointB, pointC, pointD, pointE;

    printf("\n\n");
    printf("Enter SR_x co-rodinates for point A:\n");
    scanf("%f", &pointA.SR_x);
    printf("Enter SR_y co-rodinates for point A:\n");
    scanf("%f", &pointA.SR_y);

    printf("\n\n");
    printf("Enter SR_x co-rodinates for point B:\n");
    scanf("%f", &pointB.SR_x);
    printf("Enter SR_y co-rodinates for point B:\n");
    scanf("%f", &pointB.SR_y);

    printf("\n\n");
    printf("Enter SR_x co-rodinates for point C:\n");
    scanf("%f", &pointC.SR_x);

    printf("Enter SR_y co-rodinates for point C:\n");
    scanf("%f", &pointC.SR_y);

    printf("\n\n");
    printf("Enter SR_x co-rodinates for point D:\n");
    scanf("%f", &pointD.SR_x);

    printf("Enter SR_y co-rodinates for point D:\n");
    scanf("%f", &pointD.SR_y);

    printf("\n\n");
    printf("Enter SR_x co-rodinates for point E:\n");
    scanf("%f", &pointE.SR_x);

    printf("Enter SR_y co-rodinates for point E:\n");
    scanf("%f", &pointE.SR_y);

    printf("\n\n");
    printf("Co-oridinates (SR_x,SR_y) of point A are: (%f, %f)\n\n", pointA.SR_x, pointA.SR_y);
    printf("Co-oridinates (SR_x,SR_y) of point B are: (%f, %f)\n\n", pointB.SR_x, pointB.SR_y);
    printf("Co-oridinates (SR_x,SR_y) of point C are: (%f, %f)\n\n", pointC.SR_x, pointC.SR_y);
    printf("Co-oridinates (SR_x,SR_y) of point D are: (%f, %f)\n\n", pointD.SR_x, pointD.SR_y);
    printf("Co-oridinates (SR_x,SR_y) of point E are: (%f, %f)\n\n", pointE.SR_x, pointE.SR_y);

    printf("\n\n--End--\n\n");
    return (0);
}