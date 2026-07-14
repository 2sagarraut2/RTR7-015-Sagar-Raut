#include <stdio.h>

int main(void)
{
    int SR_iArray[5][3] = {{1, 2, 3}, {2, 4, 6}, {3, 6, 9}, {4, 8, 12}, {5, 10, 15}};

    int SR_intSize = 0;
    int SR_iArraySize = 0;
    int SR_iArrayNumElements = 0, SR_iArrayNumRows = 0, SR_iArrayNumCols = 0;

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

    printf("***ROW1***\n");
    printf("SR_iArray[0][0] = %d\n\n", SR_iArray[0][0]);
    printf("SR_iArray[0][1] = %d\n\n", SR_iArray[0][1]);
    printf("SR_iArray[0][2] = %d\n\n", SR_iArray[0][2]);

    printf("\n\n");
    printf("***ROW2***\n");
    printf("SR_iArray[1][0] = %d\n\n", SR_iArray[1][0]);
    printf("SR_iArray[1][1] = %d\n\n", SR_iArray[1][1]);
    printf("SR_iArray[1][2] = %d\n\n", SR_iArray[1][2]);

    printf("\n\n");
    printf("***ROW3***\n");
    printf("SR_iArray[2][0] = %d\n\n", SR_iArray[2][0]);
    printf("SR_iArray[2][1] = %d\n\n", SR_iArray[2][1]);
    printf("SR_iArray[2][2] = %d\n\n", SR_iArray[2][2]);

    printf("\n\n");
    printf("***ROW4***\n");
    printf("SR_iArray[3][0] = %d\n\n", SR_iArray[3][0]);
    printf("SR_iArray[3][1] = %d\n\n", SR_iArray[3][1]);
    printf("SR_iArray[3][2] = %d\n\n", SR_iArray[3][2]);

    printf("\n\n");
    printf("***ROW5***\n");
    printf("SR_iArray[4][0] = %d\n\n", SR_iArray[4][0]);
    printf("SR_iArray[4][1] = %d\n\n", SR_iArray[4][1]);
    printf("SR_iArray[4][2] = %d\n\n", SR_iArray[4][2]);

    printf("\n\n--End--\n\n");
    return (0);
}