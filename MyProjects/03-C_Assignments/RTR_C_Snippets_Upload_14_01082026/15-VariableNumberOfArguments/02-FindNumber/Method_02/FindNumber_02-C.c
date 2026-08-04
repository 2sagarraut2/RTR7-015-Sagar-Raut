#include <stdio.h>
#include <stdarg.h>

#define NUMBER_TO_FIND 8
#define NUM_ELEMENTS 10

int main(void)
{
    void FindNumber(int, int, ...);

    printf("\n\n");

    FindNumber(NUMBER_TO_FIND, NUM_ELEMENTS, 6, 6, 8, 8, 9, 8, 5, 8, 0, 7);

    printf("\n\n--End--\n\n");
    return (0);
}

void FindNumber(int numToBeFind, int totalNumbers, ...)
{
    int va_FindNumber(int, int, va_list);

    int SR_count = 0;
    int SR_n;
    va_list SR_numbersList;

    va_start(SR_numbersList, totalNumbers);

    SR_count = va_FindNumber(numToBeFind, totalNumbers, SR_numbersList);

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

int va_FindNumber(int SR_numToFind, int SR_num, va_list SR_list)
{
    int SR_countOfNumbers = 0;
    int SR_n;

    while (SR_num)
    {
        SR_n = va_arg(SR_list, int);

        if (SR_n == SR_numToFind)
        {
            SR_countOfNumbers++;
        }
        SR_num--;
    }

    return (SR_countOfNumbers);
}