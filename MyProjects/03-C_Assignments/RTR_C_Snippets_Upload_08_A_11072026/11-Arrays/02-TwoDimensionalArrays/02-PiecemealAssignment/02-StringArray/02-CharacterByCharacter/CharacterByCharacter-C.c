#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char SR_strArray[5][10];

    int SR_charSize = 0, SR_strArraySize = 0, SR_srtArrayNumElements = 0, SR_strArrayNumRows = 0, SR_strArrayNumCols = 0;
    int SR_i = 0;

    printf("\n\n");

    SR_charSize = sizeof(char);

    SR_strArraySize = sizeof(SR_strArray);
    printf("Size of 2D character array is %d\n\n", SR_strArraySize);

    SR_strArrayNumRows = SR_strArraySize / sizeof(SR_strArray[0]);
    printf("Number of rows in 2D character array is %d\n\n", SR_strArrayNumRows);

    SR_strArrayNumCols = sizeof(SR_strArray[0]) / SR_charSize;
    printf("Number of rows in 2D character array is %d\n\n", SR_strArrayNumCols);

    SR_srtArrayNumElements = SR_strArrayNumRows * SR_strArrayNumCols;
    printf("Total number of elements in 2D character array is %d\n\n", SR_srtArrayNumElements);

    SR_strArray[0][0] = 'M';
    SR_strArray[0][1] = 'y';
    SR_strArray[0][2] = '\0';

    SR_strArray[1][0] = 'N';
    SR_strArray[1][1] = 'a';
    SR_strArray[1][2] = 'm';
    SR_strArray[1][3] = 'e';
    SR_strArray[1][4] = '\0';

    SR_strArray[2][0] = 'I';
    SR_strArray[2][1] = 's';
    SR_strArray[2][2] = '\0';

    SR_strArray[3][0] = 'S';
    SR_strArray[3][1] = 'a';
    SR_strArray[3][2] = 'g';
    SR_strArray[3][3] = 'a';
    SR_strArray[3][4] = 'r';
    SR_strArray[3][5] = '\0';

    SR_strArray[4][0] = 'R';
    SR_strArray[4][1] = 'a';
    SR_strArray[4][2] = 'u';
    SR_strArray[4][3] = 't';
    SR_strArray[4][4] = '\0';

    printf("\n\n");
    printf("The string in 2D character array are\n\n");

    for (SR_i = 0; SR_i < SR_strArrayNumRows; SR_i++)
    {
        printf("%s ", SR_strArray[SR_i]);
    }

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
