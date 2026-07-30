#include <stdio.h>

struct Rectangle
{
    struct MyPoint
    {
        int SR_x;
        int SR_y;

    } SR_point01, SR_point02;
} rect;

int main(void)
{

    int length = 0, breadth = 0, area = 0;

    printf("\n\n");
    printf("Enter leftmost SR_x-co-ordinate for rectangle: ");
    scanf("%d", &rect.SR_point01.SR_x);

    printf("\n\n");
    printf("Enter bottommost SR_y-co-ordinate for rectangle: ");
    scanf("%d", &rect.SR_point01.SR_y);

    printf("\n\n");
    printf("Enter rightmost SR_x-co-ordinate for rectangle: ");
    scanf("%d", &rect.SR_point02.SR_x);

    printf("\n\n");
    printf("Enter topmost SR_y-co-ordinate for rectangle: ");
    scanf("%d", &rect.SR_point02.SR_y);

    printf("\n\nPointes given are\n");
    printf("leftmost SR_x-co-ordinate for rectangle: %d\n", rect.SR_point01.SR_x);
    printf("bottommost SR_y-co-ordinate for rectangle: %d\n", rect.SR_point01.SR_y);
    printf("rightmost SR_x-co-ordinate for rectangle: %d\n", rect.SR_point02.SR_x);
    printf("topmost SR_y-co-ordinate for rectangle: %d\n\n", rect.SR_point02.SR_x);

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