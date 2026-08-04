#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLUMNS_ONE 3
#define NUM_COLUMNS_TWO 8

int main(void)
{
    int *iArray[NUM_ROWS];
    int SR_i, SR_j;

    printf("\n\n");
    printf("First memory allocation for 2D integer array \n\n");
    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        iArray[SR_i] = (int *)malloc(NUM_COLUMNS_ONE * sizeof(int));
        if (iArray[SR_i] == NULL)
        {
            printf("Failed to allocate memory for %d rows of 2D integer array\n", SR_i);
        }
        else
        {
            printf("Memory allocation for row %d of 2D integer array Succeeded\n", SR_i);
        }
    }

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS_ONE; SR_j++)
        {
            iArray[SR_i][SR_j] = (SR_i + 1) * (SR_j + 1);
        }
    }

    printf("\n\n");
    printf("Displaying 2D array\n");
    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS_ONE; SR_j++)
        {
            printf("iArray[%d][%d] = %d\n", SR_i, SR_j, iArray[SR_i][SR_j]);
        }
        printf("\n\n");
    }

    for (SR_i = (NUM_ROWS - 1); SR_i >= 0; SR_i--)
    {
        free(iArray[SR_i]);
        iArray[SR_i] = NULL;
        printf("Memory allocated for %d rows has been released!\n", SR_i);
    }

    printf("\n\n");
    printf("Second memory alocation for 2D integer array\n");
    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        iArray[SR_i] = (int *)malloc(NUM_COLUMNS_TWO * sizeof(int));
        if (iArray[SR_i] == NULL)
        {
            printf("Failed to allocate memory for %d rows of 2D integer array\n", SR_i);
        }
        else
        {
            printf("Memory allocation for row %d of 2D integer array Succeeded\n", SR_i);
        }
    }

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS_TWO; SR_j++)
        {
            iArray[SR_i][SR_j] = (SR_i + 1) * (SR_j + 1);
        }
    }

    printf("\n\n");
    printf("Displaying 2D array\n");
    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLUMNS_TWO; SR_j++)
        {
            printf("iArray[%d][%d] = %d\n", SR_i, SR_j, iArray[SR_i][SR_j]);
        }
        printf("\n\n");
    }

    for (SR_i = (NUM_ROWS - 1); SR_i >= 0; SR_i--)
    {
        free(iArray[SR_i]);
        iArray[SR_i] = NULL;
        printf("Memory allocated for %d rows has been released!\n", SR_i);
    }

    printf("\n\n--End--\n\n");
    return (0);
}