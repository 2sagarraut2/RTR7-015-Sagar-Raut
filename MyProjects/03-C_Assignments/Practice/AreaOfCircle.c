#include <stdio.h>

int main()
{
    // function declarartion
    float multiplication(float, float);

    // variable declaration
    float radius = 3.4;
    float pi = 3.14;
    float area_of_circle = 0;

    // code
    area_of_circle = multiplication(pi, radius);

    printf("Area of circle is %f", area_of_circle);

    return (0);
}

float multiplication(float pi, float radius)
{
    float area_of_circle = 0;
    area_of_circle = pi * radius * radius;

    return (area_of_circle);
}