#include <stdio.h>

int main(void)
{
    int SR_2D_Array[7][4];
    int iArraySize = 0;
    int iArrayRows = 0;
    int iArrayColumns = 0;
    int iArrayNumElements = 0;

    iArrayRows = sizeof(SR_2D_Array) / sizeof(SR_2D_Array[0]);
    iArrayColumns = sizeof(SR_2D_Array[0]) / sizeof(SR_2D_Array[0][0]);
    iArrayNumElements = iArrayRows * iArrayColumns;

    printf("Number of Row = %d\n", iArrayRows);
    printf("Number of columns = %d\n", iArrayColumns);
    printf("Number of Elements = %d\n\n", iArrayNumElements);

    SR_2D_Array[0][0] = 23;
    SR_2D_Array[0][1] = 45;
    SR_2D_Array[0][2] = 456;
    SR_2D_Array[0][3] = 678;

    SR_2D_Array[1][0] = 34;
    SR_2D_Array[1][1] = 67;
    SR_2D_Array[1][2] = 43;
    SR_2D_Array[1][3] = 89;

    SR_2D_Array[2][0] = 111;
    SR_2D_Array[2][1] = 222;
    SR_2D_Array[2][2] = 333;
    SR_2D_Array[2][3] = 444;

    SR_2D_Array[3][0] = 2678;
    SR_2D_Array[3][1] = 5674;
    SR_2D_Array[3][2] = 453;
    SR_2D_Array[3][3] = 234;

    SR_2D_Array[4][0] = 646;
    SR_2D_Array[4][1] = 544;
    SR_2D_Array[4][2] = 345;
    SR_2D_Array[4][3] = 453;

    SR_2D_Array[5][0] = 907;
    SR_2D_Array[5][1] = 405;
    SR_2D_Array[5][2] = 596;
    SR_2D_Array[5][3] = 595;

    SR_2D_Array[6][0] = 456;
    SR_2D_Array[6][1] = 675;
    SR_2D_Array[6][2] = 897;
    SR_2D_Array[6][3] = 436;

    printf("Elements are as follows:\n");

    for (int i = 0; i < iArrayRows; i++)
    {
        for (int j = 0; j < iArrayColumns; j++)
        {
            printf("SR_2D_Array[%d][%d] = %d\n", i, j, SR_2D_Array[i][j]);
        }
        printf("\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}