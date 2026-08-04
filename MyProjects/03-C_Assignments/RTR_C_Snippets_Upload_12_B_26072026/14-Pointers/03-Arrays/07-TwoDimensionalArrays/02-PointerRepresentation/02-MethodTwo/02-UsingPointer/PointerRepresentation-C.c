#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{
    int SR_i, SR_j;
    int **ptr_iArray = NULL;

    printf("\n\n");

    ptr_iArray = (int **)malloc(NUM_ROWS * sizeof(int *));

    if (ptr_iArray == NULL)
    {
        printf("Memory allocation of the 1D array of base addresses of %d rows failed! exiting now!\n\n", NUM_ROWS);
        exit(0);
    }
    else
    {
        printf("Memory allocation of the 1D array of base addresses of %d rows succeded!\n\n", NUM_ROWS);
    }

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        ptr_iArray[SR_i] = (int *)malloc(NUM_COLUMNS * sizeof(int));

        if (ptr_iArray == NULL)
        {
            printf("Memory allocation for columns of row %d failed\n\n", SR_i);
            exit(0);
        }
        else
        {
            printf("Memory allocation to the columns of row %d successful!", SR_i);
        }
    }

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS; SR_j++)
        {
            *(*(ptr_iArray + SR_i) + SR_j) = (SR_i + 1) * (SR_j + 1);
        }
    }

    printf("\n\n");
    printf("2D integer array elements along with adresss \n");
    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS; SR_j++)
        {
            printf("ptr_iArray_Row[%d][%d] = %d \t \t at address &ptr_iArray_Row[%d][%d] : %p\n", SR_i, SR_j, ptr_iArray[SR_i][SR_j], SR_i, SR_j, &ptr_iArray[SR_i][SR_j]);
        }
    }

    printf("\n\n");
    for (SR_i = (NUM_ROWS - 1); SR_i >= 0; SR_i--)
    {
        if (*(ptr_iArray + SR_i))
        {
            free(*(ptr_iArray + SR_i));
            *(ptr_iArray + SR_i) = NULL;
            printf("Memory allocated for row %d has been released\n", SR_i);
        }
    }

    if (ptr_iArray)
    {
        free(ptr_iArray);
        ptr_iArray = NULL;
        printf("Memory allocated to ptr_iArray has been released!\n\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}