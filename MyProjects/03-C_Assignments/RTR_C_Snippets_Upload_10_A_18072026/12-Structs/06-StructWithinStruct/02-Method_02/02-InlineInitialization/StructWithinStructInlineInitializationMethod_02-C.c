#include <stdio.h>

struct MyPoint
{
    int SR_x;
    int SR_y;
};

struct Rectangle
{
    struct MyPoint SR_point01, SR_point02;
};

struct Rectangle rect = {{2, 3}, {5, 6}};

int main(void)
{

    int length = 0, breadth = 0, area = 0;

    length = rect.SR_point02.SR_y - rect.SR_point01.SR_y;

    if (length < 0)
    {
        length = length * -1;
    }

    breadth = rect.SR_point02.SR_x - rect.SR_point01.SR_x;

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