#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char chArray[MAX_STRING_LENGTH], chArraySpacesRemoved[MAX_STRING_LENGTH];
    int iStringLength;
    int i, j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    iStringLength = MyStrlen(chArray);
    j = 0;

    for (i = 0; i < iStringLength; i++)
    {
        if (chArray[i] == ' ')
        {
            continue;
        }
        else
        {
            chArraySpacesRemoved[j] = chArray[i];
            j++;
        }
    }

    chArraySpacesRemoved[j] = '\0';

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", chArray);

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", chArraySpacesRemoved);

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