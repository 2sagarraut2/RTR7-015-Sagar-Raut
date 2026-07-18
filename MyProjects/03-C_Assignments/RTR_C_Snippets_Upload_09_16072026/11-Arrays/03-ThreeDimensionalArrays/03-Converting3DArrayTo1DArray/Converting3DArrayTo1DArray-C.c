#include <stdio.h>

#define SR_NUM_ROW 5
#define SR_NUM_COLS 3
#define SR_DEPTH 2

int main(void)
{
    int SR_iArray[5][3][2] = {{{9, 18}, {27, 36}, {45, 54}},
                              {{3, 6}, {9, 12}, {15, 18}},
                              {{7, 14}, {21, 28}, {35, 42}},
                              {{6, 12}, {18, 24}, {30, 36}},
                              {{2, 4}, {6, 8}, {10, 12}}};
    int SR_i = 0, SR_j = 0, SR_k = 0;

    int SR_iArray_1D[SR_NUM_ROW * SR_NUM_COLS * SR_DEPTH];

    printf("\n\n");
    printf("Elements in 3D array:\n\n");

    for (SR_i = 0; SR_i < SR_NUM_ROW; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_NUM_COLS; SR_j++)
        {
            for (SR_k = 0; SR_k < SR_DEPTH; SR_k++)
            {
                printf("SR_iArray[%d][%d][%d] = %d\n", SR_i, SR_j, SR_k, SR_iArray[SR_i][SR_j][SR_k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (SR_i = 0; SR_i < SR_NUM_ROW; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_NUM_COLS; SR_j++)
        {
            for (SR_k = 0; SR_k < SR_DEPTH; SR_k++)
            {
                SR_iArray_1D[(SR_i * SR_NUM_COLS * SR_DEPTH) + (SR_j * SR_DEPTH) + SR_k] = SR_iArray[SR_i][SR_j][SR_k];
            }
        }
    }

    printf("Elements in 1D array:\n\n");
    for (SR_i = 0; SR_i < (SR_NUM_ROW * SR_NUM_COLS * SR_DEPTH); SR_i++)
    {
        printf("iArray1D[%d] = %d\n", SR_i, SR_iArray_1D[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}