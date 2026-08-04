#include <stdio.h>
#include <stdarg.h>

#define NUMBER_TO_FIND 3
#define NUM_ELEMENTS 10

int main(void)
{
    void FindNumber(int, int, ...);

    printf("\n\n");

    FindNumber(NUMBER_TO_FIND, NUM_ELEMENTS, 2, 6, 3, 8, 9, 4, 5, 3, 0, 7);

    printf("\n\n--End--\n\n");
    return (0);
}

void FindNumber(int numToBeFind, int numEle, ...)
{
    int SR_count = 0;
    int SR_n;
    va_list SR_numbersList;

    va_start(SR_numbersList, numEle);

    while (numEle)
    {

        SR_n = va_arg(SR_numbersList, int);
        if (SR_n == numToBeFind)
        {
            SR_count++;
        }
        numEle--;
    }

    if (SR_count == 0)
    {
        printf("Number %d could not found\n\n", numToBeFind);
    }
    else
    {
        printf("Number %d found %d times\n\n", numToBeFind, SR_count);
    }

    va_end(SR_numbersList);
}