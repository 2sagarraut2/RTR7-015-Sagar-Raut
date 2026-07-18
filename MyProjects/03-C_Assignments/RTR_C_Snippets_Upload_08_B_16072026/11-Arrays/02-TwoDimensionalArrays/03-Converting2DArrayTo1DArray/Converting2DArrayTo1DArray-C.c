#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main(void)
{
    int SR_iArray2D[NUM_ROWS][NUM_COLS];

    int SR_iArray1D[NUM_ROWS * NUM_COLS];

    int SR_i, SR_j, SR_num;

    printf("Please enter elements for 2D Array\n\n");

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        printf("Please enter element for row number: %d \n", (SR_i + 1));
        for (SR_j = 0; SR_j < NUM_COLS; SR_j++)
        {
            printf("Please enter element  number %d \n", (SR_j + 1));
            scanf("%d", &SR_num);
            SR_iArray2D[SR_i][SR_j] = SR_num;
        }
        printf("\n\n");
    }

    printf("Display of 2D Array");

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        printf("*** Row %d ***\n", (SR_i + 1));
        for (SR_j = 0; SR_j < NUM_COLS; SR_j++)
        {
            printf("Element at position [%d][%d] = %d\n", SR_i, SR_j, SR_iArray2D[SR_i][SR_j]);
        }
    }

    printf("Converting 2D array to 1D array\n");

    for (SR_i = 0; SR_i < NUM_ROWS; SR_i++)
    {
        for (SR_j = 0; SR_j < NUM_COLS; SR_j++)
        {
            SR_iArray1D[(SR_i * NUM_COLS) + SR_j] = SR_iArray2D[SR_i][SR_j];
        }
    }

    printf("\n\n");
    printf("One-dimetional array of integers\n");
    for (SR_i = 0; SR_i < (NUM_ROWS * NUM_COLS); SR_i++)
    {
        printf("SR_iArray1D[%d] = %d\n", SR_i, SR_iArray1D[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}