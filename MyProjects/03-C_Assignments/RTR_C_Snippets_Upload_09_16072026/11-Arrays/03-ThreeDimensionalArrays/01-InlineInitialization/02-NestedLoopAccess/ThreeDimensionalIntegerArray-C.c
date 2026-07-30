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
    int SR_i = 0, SR_j = 0, SR_k = 0;

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

    for (SR_i = 0; SR_i < SR_iArrayWidth; SR_i++)
    {
        printf("*** Row %d ***\n", (SR_i + 1));
        for (SR_j = 0; SR_j < SR_iArrayHeight; SR_j++)
        {
            printf("*** Columns %d ***\n", (SR_j + 1));
            for (SR_k = 0; SR_k < SR_iArrayDepth; SR_k++)
            {
                printf("SR_iArray[%d][%d][%d] = %d\n", SR_i, SR_j, SR_k, SR_iArray[SR_i][SR_j][SR_k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}