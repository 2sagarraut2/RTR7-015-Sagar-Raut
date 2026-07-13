#include <stdio.h>

int main(void)
{
    int iArray[] = {9, 30, 6, 12, 98, 95, 20, 23, 2, 45};

    int intSize;
    int iArraySize;
    int iArrayNumElements;

    float fArray[] = {1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f, 7.8f, 8.9f, 9.9f, 10.5f};
    int floatSize;
    int fArraySize;
    int fArrayNumElements;

    char cArray[] = {'A', 'S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};
    int charSize;
    int cArraySize;
    int cArrayNumElements;

    printf("\n\n");

    printf("In-line initialization and piece-meal display of elements of Array 'iArray[]':\n\n");

    printf("iArray[0] (0th element) = %d\n", iArray[0]);
    printf("iArray[1] (1st element) = %d\n", iArray[1]);
    printf("iArray[2] (2nd element) = %d\n", iArray[2]);
    printf("iArray[3] (3rd element) = %d\n", iArray[3]);
    printf("iArray[4] (4th element) = %d\n", iArray[4]);
    printf("iArray[5] (5th element) = %d\n", iArray[5]);
    printf("iArray[6] (6th element) = %d\n", iArray[6]);
    printf("iArray[7] (7th element) = %d\n", iArray[7]);
    printf("iArray[8] (8th element) = %d\n", iArray[8]);
    printf("iArray[9] (9th element) = %d\n", iArray[9]);

    intSize = sizeof(int);
    iArraySize = sizeof(iArray);
    iArrayNumElements = iArraySize / intSize;
    printf("Size of data type int = %d bytes\n", intSize);
    printf("Number of elements in int Array 'iArray' = %d elements\n", iArrayNumElements);
    printf("Size of Array 'iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", iArrayNumElements, intSize, iArraySize);

    printf("\n\n");
    printf("in-line initialization and piece-meal display of Array fArray[]: \n\n");

    printf("fArray[0] (0th element) = %f\n", fArray[0]);
    printf("fArray[1] (1st element) = %f\n", fArray[1]);
    printf("fArray[2] (2nd element) = %f\n", fArray[2]);
    printf("fArray[3] (3rd element) = %f\n", fArray[3]);
    printf("fArray[4] (4th element) = %f\n", fArray[4]);
    printf("fArray[5] (5th element) = %f\n", fArray[5]);
    printf("fArray[6] (6th element) = %f\n", fArray[6]);
    printf("fArray[7] (7th element) = %f\n", fArray[7]);
    printf("fArray[8] (8th element) = %f\n", fArray[8]);
    printf("fArray[9] (9th element) = %f\n", fArray[9]);

    floatSize = sizeof(float);
    fArraySize = sizeof(fArray);
    fArrayNumElements = fArraySize / floatSize;
    printf("Size of data type float = %d bytes\n", floatSize);
    printf("Number of elements in float Array 'fArray' = %d elements\n", fArrayNumElements);
    printf("Size of Array 'iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", fArrayNumElements, floatSize, fArraySize);

    printf("\n\n");
    printf("in-line initialization and piece-meal display of Array CArray[]: \n\n");

    printf("cArray[0] (0th element) = %c\n", cArray[0]);
    printf("cArray[1] (1st element) = %c\n", cArray[1]);
    printf("cArray[2] (2nd element) = %c\n", cArray[2]);
    printf("cArray[3] (3rd element) = %c\n", cArray[3]);
    printf("cArray[4] (4th element) = %c\n", cArray[4]);
    printf("cArray[5] (5th element) = %c\n", cArray[5]);
    printf("cArray[6] (6th element) = %c\n", cArray[6]);
    printf("cArray[7] (7th element) = %c\n", cArray[7]);
    printf("cArray[8] (8th element) = %c\n", cArray[8]);
    printf("cArray[9] (9th element) = %c\n", cArray[9]);

    charSize = sizeof(char);
    cArraySize = sizeof(cArray);
    cArrayNumElements = cArraySize / charSize;
    printf("Size of data type char = %d bytes\n", charSize);
    printf("Number of elements in char Array 'cArray' = %d elements\n", cArrayNumElements);
    printf("Size of Array 'cArray[]' (%d elements * %d Bytes) = %d bytes\n\n", cArrayNumElements, charSize, cArraySize);

    printf("\n\n--End--\n\n");
    return (0);
}