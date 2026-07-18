#include <stdio.h>

int main(void)
{
    int iArrayOne[4];
    int iArrayTwo[4][2];
    int iArrayThree[50][50][5];

    int numRow2D = 0;
    int numCols2D = 0;

    int numRow3D = 0;
    int numCols3D = 0;
    int depth3D = 0;

    printf("\n\n");
    printf("Size of 1D integer array iArrayOne = %lu\n", sizeof(iArrayOne));
    printf("Number of elements in 1D array is iArrayOne = %lu\n", sizeof(iArrayOne) / sizeof(int));

    printf("\n\n");
    printf("size of 2D integer array iArrayTwo %lu\n", sizeof(iArrayTwo));

    printf("Number of rows in 2D integer array iArrayTwo = %lu\n", sizeof(iArrayTwo) / sizeof(iArrayTwo[0]));
    numRow2D = sizeof(iArrayTwo) / sizeof(iArrayTwo[0]);

    printf("Number of elements (columns) in each row in 2D integer array iArrayTwo = %lu\n", sizeof(iArrayTwo[0]) / sizeof(iArrayTwo[0][0]));
    printf("Total number of elements in 2D array iArrayTwo = %d\n", numRow2D * numCols2D);

    printf("\n\n");

    printf("\n\n");
    printf("Size of 3D integer array iArrayThree = %lu\n", sizeof(iArrayThree));
    printf("Number of rows in 3D integer array iArrayThree %lu\n", sizeof(iArrayThree) / sizeof(iArrayThree[0]));
    numRow3D = (sizeof(iArrayThree) / sizeof(iArrayThree[0]));
    numCols3D = (sizeof(iArrayThree[0]) / sizeof(iArrayThree[0][0]));
    depth3D = (sizeof(iArrayThree[0][0]) / sizeof(int));

    printf("Number of elements (columns) in one row in 3D integer array iArrayThree = %lu\n", (sizeof(iArrayThree[0]) / sizeof(iArrayThree[0][0])));

    printf("Nunber of elements (depth) in one column in row in 3D integer array iArrayThree = %lu\n", (sizeof(iArrayThree[0][0]) / sizeof(iArrayThree[0][0][0])));

    printf("Total elements in 3D ineteger array iArrayThree = %d\n", (numRow3D * numCols3D * depth3D));

    printf("\n\n--End--\n\n");
    return (0);
}