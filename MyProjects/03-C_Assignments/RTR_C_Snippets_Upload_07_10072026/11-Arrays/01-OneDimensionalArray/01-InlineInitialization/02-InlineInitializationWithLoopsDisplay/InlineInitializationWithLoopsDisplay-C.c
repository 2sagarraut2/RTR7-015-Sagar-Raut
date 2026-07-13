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

    int i;

    printf("\n\n");
    iArraySize = sizeof(iArray);
    iArrayNumElements = iArraySize / intSize;

    for (i = 0; i < iArrayNumElements; i++)
    {
        printf("iArray[%d] (elements %d) = %d\n", i, (i + 1), iArray[i]);
    }

    intSize = sizeof(int);
    iArraySize = sizeof(iArray);
    iArrayNumElements = iArraySize / intSize;
    printf("Size of data type int = %d bytes\n", intSize);
    printf("Number of elements in int Array 'iArray' = %d elements\n", iArrayNumElements);
    printf("Size of Array 'iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", iArrayNumElements, intSize, iArraySize);

    printf("\n\n");
    fArraySize = sizeof(fArray);
    fArrayNumElements = fArraySize / floatSize;

    for (i = 0; i < fArrayNumElements; i++)
    {
        printf("fArray[%d] (elements %d) = %f\n", i, (i + 1), fArray[i]);
    }

    floatSize = sizeof(float);
    fArraySize = sizeof(fArray);
    fArrayNumElements = fArraySize / floatSize;
    printf("Size of data type float = %d bytes\n", floatSize);
    printf("Number of elements in float Array 'fArray' = %d elements\n", fArrayNumElements);
    printf("Size of Array 'fArray[]' (%d elements * %d Bytes) = %d bytes\n\n", fArrayNumElements, floatSize, fArraySize);

    printf("\n\n");
    cArraySize = sizeof(cArray);
    cArrayNumElements = cArraySize / charSize;

    for (i = 0; i < cArrayNumElements; i++)
    {
        printf("cArray[%d] (elements %d) = %c\n", i, (i + 1), cArray[i]);
    }

    charSize = sizeof(char);
    cArraySize = sizeof(cArray);
    cArrayNumElements = cArraySize / charSize;
    printf("Size of data type char = %d bytes\n", charSize);
    printf("Number of elements in char Array 'cArray' = %d elements\n", cArrayNumElements);
    printf("Size of Array 'cArray[]' (%d elements * %d Bytes) = %d bytes\n\n", cArrayNumElements, charSize, cArraySize);

    printf("\n\n--End--\n\n");
    return (0);
}