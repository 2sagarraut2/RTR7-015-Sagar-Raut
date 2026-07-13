#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char chArray[MAX_STRING_LENGTH];
    int iStringLength;
    int i;
    int worCount = 0, spaceCount = 0;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    iStringLength = MyStrlen(chArray);

    for (i = 0; i < iStringLength; i++)
    {
        switch (chArray[i])
        {
        case 32:
            spaceCount++;
            break;

        default:
            break;
        }
    }

    worCount = spaceCount + 1;

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", chArray);

    printf("\n\n");
    printf("Number of space in the input string is %d\n", spaceCount);
    printf("Number of space in the input string are %d\n", worCount);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int stringLength = 0;

    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
        {
            break;
        }
        else
        {
            stringLength++;
        }
    }

    return (stringLength);
}