#include <stdio.h>
#include <stdlib.h>

#define SR_NUM_ROWS 5
#define SR_NUM_COLUMNS 3

int main(void)
{
    int SR_iArray[SR_NUM_ROWS][SR_NUM_COLUMNS];
    int SR_i = 0, SR_j = 0;

    int *ptr_iArray_Row = NULL;

    for (SR_i = 0; SR_i < SR_NUM_ROWS; SR_i++)
    {
        ptr_iArray_Row = SR_iArray[SR_i];
        for (SR_j = 0; SR_j < SR_NUM_COLUMNS; SR_j++)
        {
            *(ptr_iArray_Row + SR_j) = (SR_i + 1) * (SR_j + 1);
        }
    }

    printf("\n\n");
    printf("2D integer array elements along with address: \n\n");
    for (SR_i = 0; SR_i < SR_NUM_ROWS; SR_i++)
    {
        ptr_iArray_Row = SR_iArray[SR_i];
        for (SR_j = 0; SR_j < SR_NUM_COLUMNS; SR_j++)
        {
            printf("*(ptr_iArray_Row + %d) = %d \t \t At Address (ptr_iArray_Row + j) : %p\n", SR_j, *(ptr_iArray_Row + SR_j), (ptr_iArray_Row + SR_j));
        }
        printf("\n\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}