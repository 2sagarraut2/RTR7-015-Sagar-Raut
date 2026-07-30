#include <stdio.h>

int main(void)
{
    int SR_iArray[3][5];
    int SR_intSize = 0;
    int SR_iArraySize = 0;
    int SR_iArrayNumElements = 0, SR_iArrayNumRows = 0, SR_iArrayNumCols = 0;
    int SR_i, SR_j;

    printf("\n\n");

    SR_intSize = sizeof(int);

    SR_iArraySize = sizeof(SR_iArray);
    printf("Size of 2D integer array is %d\n\n", SR_iArraySize);

    SR_iArrayNumRows = SR_iArraySize / sizeof(SR_iArray[0]);
    printf("Number of rows in 2D integer array is %d\n\n", SR_iArrayNumRows);

    SR_iArrayNumCols = sizeof(SR_iArray[0]) / SR_intSize;
    printf("Number of columns in 2D integer array is %d\n\n", SR_iArrayNumCols);

    SR_iArrayNumElements = SR_iArrayNumRows * SR_iArrayNumCols;
    printf("Number of elements in 2D integer array is %d\n\n", SR_iArrayNumElements);

    printf("\n\n");
    printf("Elements in 2D array\n\n");

    SR_iArray[0][0] = 21;
    SR_iArray[0][1] = 42;
    SR_iArray[0][2] = 63;
    SR_iArray[0][3] = 55;
    SR_iArray[0][4] = 105;

    SR_iArray[1][0] = 22;
    SR_iArray[1][1] = 44;
    SR_iArray[1][2] = 65;
    SR_iArray[1][3] = 55;
    SR_iArray[1][4] = 155;

    SR_iArray[2][0] = 23;
    SR_iArray[2][1] = 46;
    SR_iArray[2][2] = 69;
    SR_iArray[2][3] = 53;
    SR_iArray[2][4] = 175;

    for (SR_i = 0; SR_i < SR_iArrayNumRows; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_iArrayNumCols; SR_j++)
        {
            printf("SR_iArray[%d][%d] = %d\n", SR_i, SR_j, SR_iArray[SR_i][SR_j]);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}