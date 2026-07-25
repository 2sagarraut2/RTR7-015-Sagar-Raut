#include <stdio.h>
#include <string.h>

typedef struct
{
    int SR_x;
    int SR_y;
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
    printf("Enter SR_x-cordinate for point A: \n");
    scanf("%d", &point.SR_x);
    printf("Enter SR_y-cordinate for point A: \n");
    scanf("%d", &point.SR_y);

    printf("\n\n");
    printf("Point co-ordinates (SR_x, SR_y) are : (%d, %d)!!!\n\n", point.SR_x, point.SR_y);

    if (point.SR_x == 0 && point.SR_y == 0)
    {
        printf("point is at origin (%d, %d)!!!\n", point.SR_x, point.SR_y);
    }
    else
    {
        if (point.SR_x == 0)
        {
            if (point.SR_y < 0)
            {
                strcpy(PointProps.axisLocation, "Negative Y");
            }

            if (point.SR_y > 0)
            {
                strcpy(PointProps.axisLocation, "Positive Y");
            }

            PointProps.quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.axisLocation);
        }
        else if (point.SR_y == 0)
        {
            if (point.SR_x < 0)
            {
                strcpy(PointProps.axisLocation, "Negative X");
            }

            if (point.SR_x > 0)
            {
                strcpy(PointProps.axisLocation, "Positive X");
            }

            PointProps.quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.axisLocation);
        }
        else
        {
            PointProps.axisLocation[0] = '\0';

            if (point.SR_x > 0 && point.SR_y > 0)
            {
                PointProps.quadrant = 1;
            }
            else if (point.SR_x < 0 && point.SR_y > 0)
            {
                PointProps.quadrant = 2;
            }
            else if (point.SR_x < 0 && point.SR_y < 0)
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