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

    int SR_i;

    printf("\n\n");
    SR_iArraySize = sizeof(SR_iArray);
    SR_iArrayNumElements = SR_iArraySize / SR_intSize;

    for (SR_i = 0; SR_i < SR_iArrayNumElements; SR_i++)
    {
        printf("SR_iArray[%d] (elements %d) = %d\n", SR_i, (SR_i + 1), SR_iArray[SR_i]);
    }

    SR_intSize = sizeof(int);
    SR_iArraySize = sizeof(SR_iArray);
    SR_iArrayNumElements = SR_iArraySize / SR_intSize;
    printf("Size of data type int = %d bytes\n", SR_intSize);
    printf("Number of elements in int Array 'SR_iArray' = %d elements\n", SR_iArrayNumElements);
    printf("Size of Array 'SR_iArray[]' (%d elements * %d Bytes) = %d bytes\n\n", SR_iArrayNumElements, SR_intSize, SR_iArraySize);

    printf("\n\n");
    fArraySize = sizeof(SR_fArray);
    fArrayNumElements = fArraySize / floatSize;

    for (SR_i = 0; SR_i < fArrayNumElements; SR_i++)
    {
        printf("SR_fArray[%d] (elements %d) = %f\n", SR_i, (SR_i + 1), SR_fArray[SR_i]);
    }

    floatSize = sizeof(float);
    fArraySize = sizeof(SR_fArray);
    fArrayNumElements = fArraySize / floatSize;
    printf("Size of data type float = %d bytes\n", floatSize);
    printf("Number of elements in float Array 'SR_fArray' = %d elements\n", fArrayNumElements);
    printf("Size of Array 'SR_fArray[]' (%d elements * %d Bytes) = %d bytes\n\n", fArrayNumElements, floatSize, fArraySize);

    printf("\n\n");
    cArraySize = sizeof(SR_cArray);
    cArrayNumElements = cArraySize / SR_charSize;

    for (SR_i = 0; SR_i < cArrayNumElements; SR_i++)
    {
        printf("SR_cArray[%d] (elements %d) = %c\n", SR_i, (SR_i + 1), SR_cArray[SR_i]);
    }

    SR_charSize = sizeof(char);
    cArraySize = sizeof(SR_cArray);
    cArrayNumElements = cArraySize / SR_charSize;
    printf("Size of data type char = %d bytes\n", SR_charSize);
    printf("Number of elements in char Array 'SR_cArray' = %d elements\n", cArrayNumElements);
    printf("Size of Array 'SR_cArray[]' (%d elements * %d Bytes) = %d bytes\n\n", cArrayNumElements, SR_charSize, cArraySize);

    printf("\n\n--End--\n\n");
    return (0);
}