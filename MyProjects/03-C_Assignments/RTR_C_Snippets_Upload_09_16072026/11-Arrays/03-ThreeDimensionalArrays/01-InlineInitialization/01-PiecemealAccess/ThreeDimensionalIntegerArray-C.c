#include <stdio.h>

int main(void)
{
    int SR_iArray[5][3][2] = {{{9, 18}, {27, 36}, {45, 54}},
                              {{8, 16}, {24, 32}, {40, 48}},
                              {{7, 14}, {21, 28}, {35, 42}},
                              {{6, 12}, {18, 24}, {30, 36}},
                              {{2, 4}, {6, 8}, {10, 12}}};

    int SR_intSize = 0;
    int SR_iArraySize = 0;
    int SR_iArrayNumElements = 0, SR_iArrayWidth = 0, SR_iArrayHeight = 0, SR_iArrayDepth = 0;

    printf("\n\n");

    SR_intSize = sizeof(int);

    SR_iArraySize = sizeof(SR_iArray);
    printf("size of 3D array is %d\n\n", SR_iArraySize);

    SR_iArrayWidth = SR_iArraySize / sizeof(SR_iArray[0]);
    printf("Number of rows in 3D array is %d\n\n", SR_iArrayWidth);

    SR_iArrayHeight = sizeof(SR_iArray[0]) / sizeof(SR_iArray[0][0]);
    printf("Number of columns in 3D array is %d\n\n", SR_iArrayHeight);

    SR_iArrayDepth = sizeof(SR_iArray[0][0]) / SR_intSize;
    printf("Number of columns in 3D array is %d\n\n", SR_iArrayDepth);

    SR_iArrayNumElements = SR_iArrayDepth * SR_iArrayHeight * SR_iArrayWidth;
    printf("Number of elements in 3D array is %d\n\n", SR_iArrayNumElements);

    printf("\n\n");
    printf("Elements in 3D array:\n\n");

    printf("*** Row1 ****\n");
    printf("*** Column1 ****\n");

    printf("SR_iArray[0][0][0] = %d\n", SR_iArray[0][0][0]);
    printf("SR_iArray[0][0][1] = %d\n", SR_iArray[0][0][1]);
    printf("\n");

    printf("*** Column2 ****\n");

    printf("SR_iArray[0][1][0] = %d\n", SR_iArray[0][1][0]);
    printf("SR_iArray[0][1][1] = %d\n", SR_iArray[0][1][1]);
    printf("\n");

    printf("*** Column3 ****\n");

    printf("SR_iArray[0][2][0] = %d\n", SR_iArray[0][2][0]);
    printf("SR_iArray[0][2][1] = %d\n", SR_iArray[0][2][1]);
    printf("\n");

    printf("*** Row2 ****\n");
    printf("*** Column1 ****\n");

    printf("SR_iArray[1][0][0] = %d\n", SR_iArray[1][0][0]);
    printf("SR_iArray[1][0][1] = %d\n", SR_iArray[1][0][1]);
    printf("\n");

    printf("*** Column2 ****\n");

    printf("SR_iArray[1][1][0] = %d\n", SR_iArray[1][1][0]);
    printf("SR_iArray[1][1][1] = %d\n", SR_iArray[1][1][1]);
    printf("\n");

    printf("*** Column3 ****\n");

    printf("SR_iArray[1][2][0] = %d\n", SR_iArray[1][2][0]);
    printf("SR_iArray[1][2][1] = %d\n", SR_iArray[1][2][1]);
    printf("\n");

    printf("*** Row3 ****\n");
    printf("*** Column1 ****\n");

    printf("SR_iArray[2][0][0] = %d\n", SR_iArray[2][0][0]);
    printf("SR_iArray[2][0][1] = %d\n", SR_iArray[2][0][1]);
    printf("\n");

    printf("*** Column2 ****\n");

    printf("SR_iArray[2][1][0] = %d\n", SR_iArray[2][1][0]);
    printf("SR_iArray[2][1][1] = %d\n", SR_iArray[2][1][1]);
    printf("\n");

    printf("*** Column3 ****\n");

    printf("SR_iArray[2][2][0] = %d\n", SR_iArray[2][2][0]);
    printf("SR_iArray[2][2][1] = %d\n", SR_iArray[2][2][1]);
    printf("\n");

    printf("*** Row4 ****\n");
    printf("*** Column1 ****\n");

    printf("SR_iArray[3][0][0] = %d\n", SR_iArray[3][0][0]);
    printf("SR_iArray[3][0][1] = %d\n", SR_iArray[3][0][1]);
    printf("\n");

    printf("*** Column2 ****\n");

    printf("SR_iArray[3][1][0] = %d\n", SR_iArray[3][1][0]);
    printf("SR_iArray[3][1][1] = %d\n", SR_iArray[3][1][1]);
    printf("\n");

    printf("*** Column3 ****\n");

    printf("SR_iArray[3][2][0] = %d\n", SR_iArray[3][2][0]);
    printf("SR_iArray[3][2][1] = %d\n", SR_iArray[3][2][1]);
    printf("\n");

    printf("*** Row5 ****\n");
    printf("*** Column1 ****\n");

    printf("SR_iArray[4][0][0] = %d\n", SR_iArray[4][0][0]);
    printf("SR_iArray[4][0][1] = %d\n", SR_iArray[4][0][1]);
    printf("\n");

    printf("*** Column2 ****\n");

    printf("SR_iArray[4][1][0] = %d\n", SR_iArray[4][1][0]);
    printf("SR_iArray[4][1][1] = %d\n", SR_iArray[4][1][1]);
    printf("\n");

    printf("*** Column3 ****\n");

    printf("SR_iArray[4][2][0] = %d\n", SR_iArray[4][2][0]);
    printf("SR_iArray[4][2][1] = %d\n", SR_iArray[4][2][1]);
    printf("\n");

    printf("\n\n--End--\n\n");
    return (0);
}