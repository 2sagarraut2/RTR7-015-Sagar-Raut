#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrrev(char[], char[]);

    char chArrayOriginal[MAX_STRING_LENGTH], chArrayReversed[MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n");
    fgets(chArrayOriginal, MAX_STRING_LENGTH, stdin);

    MyStrrev(chArrayReversed, chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you is \n\n");
    printf("%s", chArrayOriginal);

    printf("\n\n");
    printf("Reversed string is \n\n");
    printf("%s", chArrayReversed);

    printf("\n\n--End--\n\n");
    return (0);
}

void MyStrrev(char strDestination[], char strSource[])
{
    int MyStrlen(char[]);

    int iStringLength = 0;
    int i, j, len;

    iStringLength = MyStrlen(strSource);

    len = iStringLength - 1;

    for (i = 0, j = len; i < iStringLength, j >= 0; i++, j--)
    {
        strDestination[i] = strSource[j];
    }

    strDestination[i] = '\0';
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