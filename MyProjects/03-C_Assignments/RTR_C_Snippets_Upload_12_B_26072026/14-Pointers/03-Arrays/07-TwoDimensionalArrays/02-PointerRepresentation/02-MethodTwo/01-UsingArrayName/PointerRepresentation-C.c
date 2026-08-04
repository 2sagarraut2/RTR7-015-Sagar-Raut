#include <stdio.h>

#define SR_NUM_ROWS 5
#define SR_NUM_COLUMNS 3

int main(void)
{
    int iArray[SR_NUM_COLUMNS][SR_NUM_COLUMNS];
    int SR_i, SR_j;

    for (SR_i = 0; SR_i < SR_NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_NUM_COLUMNS; SR_j++)
        {
            *(*(iArray + SR_i) + SR_j) = (SR_i + 1) * (SR_j + 1);
        }
    }

    for (SR_i = 0; SR_i < SR_NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_NUM_COLUMNS; SR_j++)
        {
            printf("*(*(iArray+%d) + %d) = %d \t \t at address (*(iArray+%d) + %d) : %p\n", SR_i, SR_j, *(*(iArray + SR_i) + SR_j), SR_i, SR_j, (*(iArray + SR_i) + SR_j));
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}