#include <stdio.h>

int main(void)
{
    int SR_iArrayOne[4];
    int SR_iArrayTwo[4][2];
    int SR_iArrayThree[50][50][5];

    int SR_numRow2D = 0;
    int SR_numCols2D = 0;

    int SR_numRow3D = 0;
    int SR_numCols3D = 0;
    int SR_depth3D = 0;

    printf("\n\n");
    printf("Size of 1D integer array SR_iArrayOne = %lu\n", sizeof(SR_iArrayOne));
    printf("Number of elements in 1D array is SR_iArrayOne = %lu\n", sizeof(SR_iArrayOne) / sizeof(int));

    printf("\n\n");
    printf("size of 2D integer array SR_iArrayTwo %lu\n", sizeof(SR_iArrayTwo));

    printf("Number of rows in 2D integer array SR_iArrayTwo = %lu\n", sizeof(SR_iArrayTwo) / sizeof(SR_iArrayTwo[0]));
    SR_numRow2D = sizeof(SR_iArrayTwo) / sizeof(SR_iArrayTwo[0]);

    printf("Number of elements (columns) in each row in 2D integer array SR_iArrayTwo = %lu\n", sizeof(SR_iArrayTwo[0]) / sizeof(SR_iArrayTwo[0][0]));
    printf("Total number of elements in 2D array SR_iArrayTwo = %d\n", SR_numRow2D * SR_numCols2D);

    printf("\n\n");

    printf("\n\n");
    printf("Size of 3D integer array SR_iArrayThree = %lu\n", sizeof(SR_iArrayThree));
    printf("Number of rows in 3D integer array SR_iArrayThree %lu\n", sizeof(SR_iArrayThree) / sizeof(SR_iArrayThree[0]));
    SR_numRow3D = (sizeof(SR_iArrayThree) / sizeof(SR_iArrayThree[0]));
    SR_numCols3D = (sizeof(SR_iArrayThree[0]) / sizeof(SR_iArrayThree[0][0]));
    SR_depth3D = (sizeof(SR_iArrayThree[0][0]) / sizeof(int));

    printf("Number of elements (columns) in one row in 3D integer array SR_iArrayThree = %lu\n", (sizeof(SR_iArrayThree[0]) / sizeof(SR_iArrayThree[0][0])));

    printf("Nunber of elements (depth) in one column in row in 3D integer array SR_iArrayThree = %lu\n", (sizeof(SR_iArrayThree[0][0]) / sizeof(SR_iArrayThree[0][0][0])));

    printf("Total elements in 3D ineteger array SR_iArrayThree = %d\n", (SR_numRow3D * SR_numCols3D * SR_depth3D));

    printf("\n\n--End--\n\n");
    return (0);
}