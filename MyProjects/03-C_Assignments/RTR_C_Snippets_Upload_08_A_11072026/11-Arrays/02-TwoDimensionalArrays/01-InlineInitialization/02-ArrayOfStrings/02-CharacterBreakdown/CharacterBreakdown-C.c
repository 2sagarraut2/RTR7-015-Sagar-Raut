#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char[]);

    char strArray[10][15] = {"Hello!", "Welcome", "to", "real", "time", "rendering", "batch", "(2025-26)", "of", "AstroMediComp."};

    int SR_iStrLength[10];
    int SR_strArraySize = 0;
    int SR_strArrayNumRows = 0;
    int SR_strActualNumChars = 0;
    int SR_i, SR_j;

    SR_strArraySize = sizeof(strArray);

    SR_strArrayNumRows = SR_strArraySize / sizeof(strArray[0]);

    for (SR_i = 0; SR_i < SR_strArrayNumRows; SR_i++)
    {
        SR_iStrLength[SR_i] = MyStrlen(strArray[SR_i]);
    }

    printf("\n\n");
    printf("The entire string array: \n\n");
    for (SR_i = 0; SR_i < SR_strArrayNumRows; SR_i++)
    {
        printf("%s ", strArray[SR_i]);
    }

    printf("\n\n");
    printf("String in the 2D Array : \n\n");

    for (SR_i = 0; SR_i < SR_strArrayNumRows; SR_i++)
    {
        printf("String number %d => %s\n\n", (SR_i + 1), strArray[SR_i]);
        for (SR_j = 0; SR_j < SR_iStrLength[SR_i]; SR_j++)
        {
            printf("Character %d = %d\n", (SR_j + 1), strArray[SR_i][SR_j]);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
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