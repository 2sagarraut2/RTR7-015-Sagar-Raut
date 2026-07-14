#include <stdio.h>

int main(void)
{
    int SR_iArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}};

    int SR_intSize = 0;
    int SR_iArraySize = 0;
    int SR_iArrayNumElements = 0, SR_iArrayNumRows = 0, SR_iArrayNumCols = 0;
    int i, j;

    printf("\n\n");
    SR_intSize = sizeof(int);

    SR_iArraySize = sizeof(SR_iArray);
    printf("Size of 2D integer array is %d\n\n", SR_iArraySize);

    SR_iArrayNumRows = SR_iArraySize / sizeof(SR_iArray[0]);
    printf("Number of rows in 2D integer array is %d\n\n", SR_iArrayNumRows);

    SR_iArrayNumCols = sizeof(SR_iArray[0]) / SR_intSize;
    printf("Number of columns in 2D integer array is %d\n\n", SR_iArrayNumCols);

    SR_iArrayNumElements = SR_iArrayNumRows * SR_iArrayNumCols;
    printf("Number of elements on 2D integer array is %d\n\n", SR_iArrayNumElements);

    for (i = 0; i < SR_iArrayNumRows; i++)
    {
        printf("*** ROW-%d ***\n", (i + 1));
        for (j = 0; j < SR_iArrayNumCols; j++)
        {
            printf("SR_iArray[%d][%d] = %d\n", i, j, SR_iArray[i][j]);
        }
        printf("\n\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}