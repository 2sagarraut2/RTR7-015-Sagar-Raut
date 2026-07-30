#include <stdio.h>

int main(void)
{
    int SR_iArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr_iArray = NULL;

    printf("\n\n");
    printf("*** Using array names as a array i.e. value of xth element of SR_iArray: SR_iArray[x] and adress of xth element of SR_iArray : &SR_iArray[x] ***\n\n");
    printf("Integer array elements and their addresses \n\n");
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[0], &SR_iArray[0]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[1], &SR_iArray[1]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[2], &SR_iArray[2]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[3], &SR_iArray[3]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[4], &SR_iArray[4]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[5], &SR_iArray[5]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[6], &SR_iArray[6]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[7], &SR_iArray[7]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[8], &SR_iArray[8]);
    printf("SR_iArray[0] = %d \t\t at address &SR_iArray[0]: %p\n", SR_iArray[9], &SR_iArray[9]);

    ptr_iArray = SR_iArray;

    printf("\n\n");
    printf("*** uisn pointer as pointer i.e. value of xth element of iArray : (ptr_iArray + x) and address of xth element of SR_iArray (ptr_iArray + x)\n\n");
    printf("Integer array elements and their addresses:\n\n");
    printf("*(ptr_iArray + 0) = %d \t \t at address (ptr_iArray + 0) : %p\n", *(ptr_iArray + 0), (ptr_iArray + 0));
    printf("*(ptr_iArray + 1) = %d \t \t at address (ptr_iArray + 1) : %p\n", *(ptr_iArray + 1), (ptr_iArray + 1));
    printf("*(ptr_iArray + 2) = %d \t \t at address (ptr_iArray + 2) : %p\n", *(ptr_iArray + 2), (ptr_iArray + 2));
    printf("*(ptr_iArray + 3) = %d \t \t at address (ptr_iArray + 3) : %p\n", *(ptr_iArray + 3), (ptr_iArray + 3));
    printf("*(ptr_iArray + 4) = %d \t \t at address (ptr_iArray + 4) : %p\n", *(ptr_iArray + 4), (ptr_iArray + 4));
    printf("*(ptr_iArray + 5) = %d \t \t at address (ptr_iArray + 5) : %p\n", *(ptr_iArray + 5), (ptr_iArray + 5));
    printf("*(ptr_iArray + 6) = %d \t \t at address (ptr_iArray + 6) : %p\n", *(ptr_iArray + 6), (ptr_iArray + 6));
    printf("*(ptr_iArray + 7) = %d \t \t at address (ptr_iArray + 7) : %p\n", *(ptr_iArray + 7), (ptr_iArray + 7));
    printf("*(ptr_iArray + 8) = %d \t \t at address (ptr_iArray + 8) : %p\n", *(ptr_iArray + 8), (ptr_iArray + 8));
    printf("*(ptr_iArray + 9) = %d \t at address (ptr_iArray + 9) : %p\n", *(ptr_iArray + 9), (ptr_iArray + 9));

    printf("\n\n--End--\n\n");
    return (0);
}