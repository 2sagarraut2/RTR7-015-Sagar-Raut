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
    int SR_i, SR_j, SR_len;

    SR_iStringLength = MyStrlen(strSource);

    SR_len = SR_iStringLength - 1;

    for (SR_i = 0, SR_j = SR_len; SR_i < SR_iStringLength, SR_j >= 0; SR_i++, SR_j--)
    {
        strDestination[SR_i] = strSource[SR_j];
    }

    strDestination[SR_i] = '\0';
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