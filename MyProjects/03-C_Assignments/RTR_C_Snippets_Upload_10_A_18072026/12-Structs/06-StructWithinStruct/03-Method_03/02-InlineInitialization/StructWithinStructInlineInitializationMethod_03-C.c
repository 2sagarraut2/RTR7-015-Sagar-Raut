#include <stdio.h>

int main(void)
{
    int length = 0, breadth = 0, area = 0;

    struct Rectangle
    {
        struct MyPoint
        {
            int SR_x;
            int SR_y;

        } SR_point01, SR_point02;
    } rect = {{6, 8}, {3, 4}};

    length = rect.SR_point02.SR_x - rect.SR_point01.SR_x;

    if (length < 0)
    {
        length = length * -1;
    }

    breadth = rect.SR_point02.SR_y - rect.SR_point01.SR_y;

    if (breadth < 0)
    {
        breadth = breadth * -1;
    }

    area = length * breadth;

    printf("\n\n");
    printf("Length of rectangle = %d\n\n", length);
    printf("Breadth of rectangle = %d\n\n", breadth);
    printf("Area of rectangle = %d\n\n", area);

    printf("\n\n--End--\n\n");
    return (0);
}