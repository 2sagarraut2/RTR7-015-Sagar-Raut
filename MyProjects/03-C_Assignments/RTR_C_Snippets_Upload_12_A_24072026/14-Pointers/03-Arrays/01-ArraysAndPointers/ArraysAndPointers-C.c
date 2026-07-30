#include <stdio.h>

int main(void)
{
    int SR_iArray[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float SR_fArray[] = {1.2f, 2.2f, 3.2f, 4.2f, 4.2f, 5.2f, 6.2f, 7.2f, 8.2f, 9.2f, 10.2f};
    double SR_dArray[] = {2.22222, 3.3333, 4.4444, 5.5555};
    char SR_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'};

    printf("\n\n");
    printf("Integer array elements and the addresses they occupy are as follows:\n\n");
    printf("SR_iArray[0] = %d \t at address : %p\n", *(SR_iArray + 0), (SR_iArray + 0));
    printf("SR_iArray[1] = %d \t at address : %p\n", *(SR_iArray + 1), (SR_iArray + 1));
    printf("SR_iArray[2] = %d \t at address : %p\n", *(SR_iArray + 2), (SR_iArray + 2));
    printf("SR_iArray[3] = %d \t at address : %p\n", *(SR_iArray + 3), (SR_iArray + 3));
    printf("SR_iArray[4] = %d \t at address : %p\n", *(SR_iArray + 4), (SR_iArray + 4));
    printf("SR_iArray[5] = %d \t at address : %p\n", *(SR_iArray + 5), (SR_iArray + 5));
    printf("SR_iArray[6] = %d \t at address : %p\n", *(SR_iArray + 6), (SR_iArray + 6));
    printf("SR_iArray[7] = %d \t at address : %p\n", *(SR_iArray + 7), (SR_iArray + 7));
    printf("SR_iArray[8] = %d \t at address : %p\n", *(SR_iArray + 8), (SR_iArray + 8));
    printf("SR_iArray[9] = %d \t at address : %p\n", *(SR_iArray + 9), (SR_iArray + 9));

    printf("\n\n");
    printf("Float array elements and the addresses they occupy are as follows:\n\n");
    printf("SR_fArray[0] = %f \t at address : %p\n", *(SR_fArray + 0), (SR_fArray + 0));
    printf("SR_fArray[1] = %f \t at address : %p\n", *(SR_fArray + 1), (SR_fArray + 1));
    printf("SR_fArray[2] = %f \t at address : %p\n", *(SR_fArray + 2), (SR_fArray + 2));
    printf("SR_fArray[3] = %f \t at address : %p\n", *(SR_fArray + 3), (SR_fArray + 3));
    printf("SR_fArray[4] = %f \t at address : %p\n", *(SR_fArray + 4), (SR_fArray + 4));
    printf("SR_fArray[5] = %f \t at address : %p\n", *(SR_fArray + 5), (SR_fArray + 5));
    printf("SR_fArray[6] = %f \t at address : %p\n", *(SR_fArray + 6), (SR_fArray + 6));
    printf("SR_fArray[7] = %f \t at address : %p\n", *(SR_fArray + 7), (SR_fArray + 7));
    printf("SR_fArray[8] = %f \t at address : %p\n", *(SR_fArray + 8), (SR_fArray + 8));
    printf("SR_fArray[9] = %f \t at address : %p\n", *(SR_fArray + 9), (SR_fArray + 9));

    printf("\n\n");
    printf("Double array elements and the addresses they occupy are as follows:\n\n");
    printf("SR_dArray[0] = %lf \t at address : %p\n", *(SR_dArray + 0), (SR_dArray + 0));
    printf("SR_dArray[1] = %lf \t at address : %p\n", *(SR_dArray + 1), (SR_dArray + 1));
    printf("SR_dArray[2] = %lf \t at address : %p\n", *(SR_dArray + 2), (SR_dArray + 2));
    printf("SR_dArray[3] = %lf \t at address : %p\n", *(SR_dArray + 3), (SR_dArray + 3));

    printf("\n\n");
    printf("Character array elements and the addresses they occupy are as follows:\n\n");
    printf("SR_cArray[0] = %c \t at address : %p\n", *(SR_cArray + 0), (SR_cArray + 0));
    printf("SR_cArray[1] = %c \t at address : %p\n", *(SR_cArray + 1), (SR_cArray + 1));
    printf("SR_cArray[2] = %c \t at address : %p\n", *(SR_cArray + 2), (SR_cArray + 2));
    printf("SR_cArray[3] = %c \t at address : %p\n", *(SR_cArray + 3), (SR_cArray + 3));
    printf("SR_cArray[4] = %c \t at address : %p\n", *(SR_cArray + 4), (SR_cArray + 4));
    printf("SR_cArray[5] = %c \t at address : %p\n", *(SR_cArray + 5), (SR_cArray + 5));
    printf("SR_cArray[6] = %c \t at address : %p\n", *(SR_cArray + 6), (SR_cArray + 6));
    printf("SR_cArray[7] = %c \t at address : %p\n", *(SR_cArray + 7), (SR_cArray + 7));
    printf("SR_cArray[8] = %c \t at address : %p\n", *(SR_cArray + 8), (SR_cArray + 8));
    printf("SR_cArray[9] = %c \t at address : %p\n", *(SR_cArray + 9), (SR_cArray + 9));
    printf("SR_cArray[10] = %c \t at address : %p\n", *(SR_cArray + 10), (SR_cArray + 10));
    printf("SR_cArray[11] = %c \t at address : %p\n", *(SR_cArray + 11), (SR_cArray + 11));
    printf("SR_cArray[12] = %c \t at address : %p\n", *(SR_cArray + 12), (SR_cArray + 12));
    printf("SR_cArray[13] = %c \t at address : %p\n", *(SR_cArray + 13), (SR_cArray + 13));

    printf("\n\n--End--\n\n");
    return (0);
}