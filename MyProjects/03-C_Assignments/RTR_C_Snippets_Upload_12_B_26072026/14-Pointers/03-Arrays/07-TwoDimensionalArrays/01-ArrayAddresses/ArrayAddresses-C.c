#include <stdio.h>

#define NUM_ROWS 5
#define NUM_COLUMNS 3

int main(void)
{

    int iArray[NUM_ROWS][NUM_COLUMNS];
    int i, j;

    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLUMNS; j++)
        {
            iArray[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("\n\n");
    printf("2D integer array along with their address\n");
    for (i = 0; i < NUM_ROWS; i++)
    {
        for (j = 0; j < NUM_COLUMNS; j++)
        {
            printf("iArray[%d][%d] = %d at address %p\n", i, j, iArray[i][j], &iArray[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}