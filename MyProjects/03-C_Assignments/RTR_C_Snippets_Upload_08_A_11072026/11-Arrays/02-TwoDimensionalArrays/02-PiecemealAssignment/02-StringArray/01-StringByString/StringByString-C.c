#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrcpy(char SR_str_destination[], char str_source[]);
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

    MyStrcpy(SR_strArray[0], "My ");
    MyStrcpy(SR_strArray[1], "Name ");
    MyStrcpy(SR_strArray[2], "is ");
    MyStrcpy(SR_strArray[3], "Sagar ");
    MyStrcpy(SR_strArray[4], "Raut ");

    printf("\n\n");
    printf("The string in 2D character array are\n\n");

    for (SR_i = 0; SR_i < SR_strArrayNumRows; SR_i++)
    {
        printf("%s", SR_strArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void MyStrcpy(char SR_str_destination[], char str_source[])
{
    int MyStrlen(char[]);

    int SR_iStringLength = 0;
    int SR_j;

    SR_iStringLength = MyStrlen(str_source);
    for (SR_j = 0; SR_j < SR_iStringLength; SR_j++)
    {
        SR_str_destination[SR_j] = str_source[SR_j];
    }

    SR_str_destination[SR_j] = '\0';
}

int MyStrlen(char str[])
{
    int SR_j;
    int SR_stringLength = 0;

    for (SR_j = 0; SR_j < SR_MAX_STRING_LENGTH; SR_j++)
    {
        if (str[SR_j] == '\0')
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
