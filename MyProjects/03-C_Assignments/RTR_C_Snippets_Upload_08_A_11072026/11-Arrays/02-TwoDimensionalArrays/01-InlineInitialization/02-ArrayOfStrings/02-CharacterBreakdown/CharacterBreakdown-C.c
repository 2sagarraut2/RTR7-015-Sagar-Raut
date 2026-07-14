#include <stdio.h>

#define SR_SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char[]);

    char strArray[10][15] = {"Hello!", "Welcome", "to", "real", "time", "rendering", "batch", "(2025-26)", "of", "AstroMediComp."};

    int SR_iStrLength[10];
    int SR_strArraySize = 0;
    int SR_strArrayNumRows = 0;
    int SR_strActualNumChars = 0;
    int i, j;

    printf("\n\n");

    SR_strArraySize = sizeof(strArray);

    SR_strArrayNumRows = SR_strArraySize / sizeof(strArray[0]);

    for (i = 0; i < SR_strArrayNumRows; i++)
    {
        SR_iStrLength[i] = MyStrlen(strArray[i]);
    }

    printf("\n\n");
    printf("The entire string array: \n\n");
    for (i = 0; i < SR_strArrayNumRows; i++)
    {
        printf("%s ", strArray[i]);
    }

    printf("\n\n");
    printf("String in the 2D Array : \n\n");

    for (i = 0; i < SR_strArrayNumRows; i++)
    {
        printf("String number %d => %s\n\n", (i + 1), strArray[i]);
        for (j = 0; j < SR_iStrLength[i]; j++)
        {
            printf("Character %d = %d\n", (j + 1), strArray[i][j]);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int SR_stringLength = 0;

    for (j = 0; j < SR_SR_MAX_STRING_LENGTH; j++)
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