#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrrev(char[], char[]);

    char SR_chArrayOriginal[SR_MAX_STRING_LENGTH], SR_chArrayReversed[SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n");
    fgets(SR_chArrayOriginal, SR_MAX_STRING_LENGTH, stdin);

    MyStrrev(SR_chArrayReversed, SR_chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you is \n\n");
    printf("%s", SR_chArrayOriginal);

    printf("\n\n");
    printf("Reversed string is \n\n");
    printf("%s", SR_chArrayReversed);

    printf("\n\n--End--\n\n");
    return (0);
}

void MyStrrev(char strDestination[], char strSource[])
{
    int MyStrlen(char[]);

    int SR_iStringLength = 0;
    int i, j, len;

    SR_iStringLength = MyStrlen(strSource);

    len = SR_iStringLength - 1;

    for (i = 0, j = len; i < SR_iStringLength, j >= 0; i++, j--)
    {
        strDestination[i] = strSource[j];
    }

    strDestination[i] = '\0';
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