#include <stdio.h>

int main(void)
{
    double SR_iArray[10];
    double *ptr_SR_iArray = NULL;
    int SR_i;

    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        SR_iArray[SR_i] = (SR_i + 1) * 2.5;
    }

    ptr_SR_iArray = SR_iArray;

    printf("\n\n");
    printf("Elements of the integer array :\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("*(ptr_SR_iArray + SR_i)[%d] = %lf\n", SR_i, *(ptr_SR_iArray + SR_i));
    }

    printf("\n\n");
    printf("Elements of the integer array and their addresses:\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("*(ptr_SR_iArray + SR_i)[%d] = %lf \t \t is at address %p\n", SR_i, *(ptr_SR_iArray + SR_i), (ptr_SR_iArray + SR_i));
    }

    printf("\n\n--End--\n\n");
    return (0);
}