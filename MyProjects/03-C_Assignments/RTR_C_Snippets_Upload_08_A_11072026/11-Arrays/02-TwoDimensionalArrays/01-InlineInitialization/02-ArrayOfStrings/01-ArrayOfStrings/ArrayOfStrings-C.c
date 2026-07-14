#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char[]);

    char strArray[10][15] = {"Hello!", "Welcome", "to", "real", "time", "rendering", "batch", "(2025-26)", "of", "AstroMediComp."};

    int SR_charSize = 0;
    int SR_strArraySize = 0;
    int SR_strArrayNumElements = 0, SR_strArrayNumRows = 0, strArrayNumCols = 0;
    int SR_strActualNumChars = 0;
    int i;

    printf("\n\n");
    SR_charSize = sizeof(char);

    SR_strArraySize = sizeof(strArray);

    SR_strArrayNumRows = SR_strArraySize / sizeof(strArray[0]);
    printf("Numer of rows (String) in 2D array (String array) is %d\n\n", SR_strArrayNumRows);

    strArrayNumCols = sizeof(strArray[0]) / SR_charSize;
    printf("Numer of columns (String) in 2D array (String array) is %d\n\n", strArrayNumCols);

    SR_strArrayNumElements = SR_strArrayNumRows * strArrayNumCols;
    printf("Total number of elements  (characters) in 2D character Array (String Array) i = %d\n\n", SR_strArrayNumElements);

    for (i = 0; i < SR_strArrayNumElements; i++)
    {
        SR_strActualNumChars = SR_strActualNumChars + MyStrlen(strArray[i]);
    }
    printf("Actual number of elemenst (character) in 2D array (String Array) is %d\n\n", SR_strActualNumChars);

    printf("\n\n");

    printf("String in the 2d Array: \n\n");

    printf("%s ", strArray[0]);
    printf("%s ", strArray[1]);
    printf("%s ", strArray[2]);
    printf("%s ", strArray[3]);
    printf("%s ", strArray[4]);
    printf("%s ", strArray[5]);
    printf("%s ", strArray[6]);
    printf("%s ", strArray[7]);
    printf("%s ", strArray[8]);
    printf("%s ", strArray[9]);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int SR_stringLength = 0;

    for (j = 0; j < SR_MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
        {
            break;
        }
        else
        {
            SR_stringLength++;
        }
    }

    return (SR_stringLength);
}