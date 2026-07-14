#include <stdio.h>

int main(void)
{
    int SR_iArray[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};

    int SR_intSize;
    int SR_iArraySize;
    int SR_iArrayNumElements;

    float SR_fArray[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f, 9.9f, 10.5f};
    int floatSize;
    int fArraySize;
    int fArrayNumElements;

    char SR_cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int SR_charSize;
    int cArraySize;
    int cArrayNumElements;

    printf("\n\n");

    printf("In-line initialization and piece-meal display of elements of Array 'SR_iArray[]':\n\n");

    printf("SR_iArray[0] (0th element) = %d\n", SR_iArray[0]);
    printf("SR_iArray[1] (1st element) = %d\n", SR_iArray[1]);
    printf("SR_iArray[2] (2nd element) = %d\n", SR_iArray[2]);
    printf("SR_iArray[3] (3rd element) = %d\n", SR_iArray[3]);
    printf("SR_iArray[4] (4th element) = %d\n", SR_iArray[4]);
    printf("SR_iArray[5] (5th element) = %d\n", SR_iArray[5]);
    printf("SR_iArray[6] (6th element) = %d\n", SR_iArray[6]);
    printf("SR_iArray[7] (7th element) = %d\n", SR_iArray[7]);
    printf("SR_iArray[8] (8th element) = %d\n", SR_iArray[8]);
    printf("SR_iArray[9] (9th element) = %d\n", SR_iArray[9]);

    SR_intSize = sizeof(int);
    SR_iArraySize = sizeof(SR_iArray);
    SR_iArrayNumElements = SR_iArraySize / SR_intSize;
    printf("Size of data type int = %d bytes\n", SR_intSize);
    printf("Number of elements in int Array 'SR_iArray' = %d elements\n", SR_iArrayNumElements);
    printf("Size of Array 'SR_iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", SR_iArrayNumElements, SR_intSize, SR_iArraySize);

    printf("\n\n");
    printf("in-line initialization and piece-meal display of Array SR_fArray[]: \n\n");

    printf("SR_fArray[0] (0th element) = %f\n", SR_fArray[0]);
    printf("SR_fArray[1] (1st element) = %f\n", SR_fArray[1]);
    printf("SR_fArray[2] (2nd element) = %f\n", SR_fArray[2]);
    printf("SR_fArray[3] (3rd element) = %f\n", SR_fArray[3]);
    printf("SR_fArray[4] (4th element) = %f\n", SR_fArray[4]);
    printf("SR_fArray[5] (5th element) = %f\n", SR_fArray[5]);
    printf("SR_fArray[6] (6th element) = %f\n", SR_fArray[6]);
    printf("SR_fArray[7] (7th element) = %f\n", SR_fArray[7]);
    printf("SR_fArray[8] (8th element) = %f\n", SR_fArray[8]);
    printf("SR_fArray[9] (9th element) = %f\n", SR_fArray[9]);

    floatSize = sizeof(float);
    fArraySize = sizeof(SR_fArray);
    fArrayNumElements = fArraySize / floatSize;
    printf("Size of data type float = %d bytes\n", floatSize);
    printf("Number of elements in float Array 'SR_fArray' = %d elements\n", fArrayNumElements);
    printf("Size of Array 'SR_iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", fArrayNumElements, floatSize, fArraySize);

    printf("\n\n");
    printf("in-line initialization and piece-meal display of Array CArray[]: \n\n");

    printf("SR_cArray[0] (0th element) = %c\n", SR_cArray[0]);
    printf("SR_cArray[1] (1st element) = %c\n", SR_cArray[1]);
    printf("SR_cArray[2] (2nd element) = %c\n", SR_cArray[2]);
    printf("SR_cArray[3] (3rd element) = %c\n", SR_cArray[3]);
    printf("SR_cArray[4] (4th element) = %c\n", SR_cArray[4]);
    printf("SR_cArray[5] (5th element) = %c\n", SR_cArray[5]);
    printf("SR_cArray[6] (6th element) = %c\n", SR_cArray[6]);
    printf("SR_cArray[7] (7th element) = %c\n", SR_cArray[7]);
    printf("SR_cArray[8] (8th element) = %c\n", SR_cArray[8]);
    printf("SR_cArray[9] (9th element) = %c\n", SR_cArray[9]);

    SR_charSize = sizeof(char);
    cArraySize = sizeof(SR_cArray);
    cArrayNumElements = cArraySize / SR_charSize;
    printf("Size of data type char = %d bytes\n", SR_charSize);
    printf("Number of elements in char Array 'SR_cArray' = %d elements\n", cArrayNumElements);
    printf("Size of Array 'SR_cArray[]' (%d elements * %d Bytes) = %d bytes\n\n", cArrayNumElements, SR_charSize, cArraySize);

    printf("\n\n--End--\n\n");
    return (0);
}