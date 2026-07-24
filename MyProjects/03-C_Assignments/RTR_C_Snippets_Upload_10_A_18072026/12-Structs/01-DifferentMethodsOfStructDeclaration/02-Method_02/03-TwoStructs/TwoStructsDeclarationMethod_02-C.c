#include <stdio.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} MyPoint;

typedef struct
{
    int quadrant;
    char axisLocation[11];
} MyPointProps;

MyPoint point;

MyPointProps PointProps;

int main(void)
{
    printf("\n\n");
    printf("Enter x-cordinate for point A: \n");
    scanf("%d", &point.x);
    printf("Enter x-cordinate for point A: \n");
    scanf("%d", &point.y);

    printf("\n\n");
    printf("Point co-ordinates (x, y) are : (%d, %d)!!!\n\n", point.x, point.y);

    if (point.x == 0 && point.y == 0)
    {
        printf("point is at origin (%d, %d)!!!\n", point.x, point.y);
    }
    else
    {
        if (point.x == 0)
        {
            if (point.y < 0)
            {
                strcpy(PointProps.axisLocation, "Negative Y");
            }

            if (point.y > 0)
            {
                strcpy(PointProps.axisLocation, "Positive Y");
            }

            PointProps.quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.axisLocation);
        }
        else if (point.y == 0)
        {
            if (point.x < 0)
            {
                strcpy(PointProps.axisLocation, "Negative X");
            }

            if (point.x > 0)
            {
                strcpy(PointProps.axisLocation, "Positive X");
            }

            PointProps.quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.axisLocation);
        }
        else
        {
            PointProps.axisLocation[0] = '\0';

            if (point.x > 0 && point.y > 0)
            {
                PointProps.quadrant = 1;
            }
            else if (point.x < 0 && point.y > 0)
            {
                PointProps.quadrant = 2;
            }
            else if (point.x < 0 && point.y < 0)
            {
                PointProps.quadrant = 3;
            }
            else
            {
                PointProps.quadrant = 4;
            }

            printf("The point lies in quadrant: %d\n\n", PointProps.quadrant);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}