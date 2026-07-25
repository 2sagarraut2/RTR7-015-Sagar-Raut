#include <stdio.h>
#include <string.h>

int main(void)
{
    typedef struct
    {
        int SR_x;
        int SR_y;
    } MyPoint;

    typedef struct
    {
        int SR_quadrant;
        char SR_axisLocation[11];
    } MyPointProps;

    MyPoint point;

    MyPointProps PointProps;

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
                strcpy(PointProps.SR_axisLocation, "Negative Y");
            }

            if (point.SR_y > 0)
            {
                strcpy(PointProps.SR_axisLocation, "Positive Y");
            }

            PointProps.SR_quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.SR_axisLocation);
        }
        else if (point.SR_y == 0)
        {
            if (point.SR_x < 0)
            {
                strcpy(PointProps.SR_axisLocation, "Negative X");
            }

            if (point.SR_x > 0)
            {
                strcpy(PointProps.SR_axisLocation, "Positive X");
            }

            PointProps.SR_quadrant = 0;
            printf("The point lies on the %s axis!!!\n\n", PointProps.SR_axisLocation);
        }
        else
        {
            PointProps.SR_axisLocation[0] = '\0';

            if (point.SR_x > 0 && point.SR_y > 0)
            {
                PointProps.SR_quadrant = 1;
            }
            else if (point.SR_x < 0 && point.SR_y > 0)
            {
                PointProps.SR_quadrant = 2;
            }
            else if (point.SR_x < 0 && point.SR_y < 0)
            {
                PointProps.SR_quadrant = 3;
            }
            else
            {
                PointProps.SR_quadrant = 4;
            }

            printf("The point lies in SR_quadrant: %d\n\n", PointProps.SR_quadrant);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}