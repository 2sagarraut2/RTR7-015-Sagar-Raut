#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrcpy(char[], char[]);

    char SR_chArrayOriginal[SR_MAX_STRING_LENGTH], SR_chArrayCopy[SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(SR_chArrayOriginal, SR_MAX_STRING_LENGTH, stdin);

    MyStrcpy(SR_chArrayCopy, SR_chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you (i.e. 'SR_chArrayOriginal[]') is: \n\n");
    printf("%s\n", SR_chArrayOriginal);

    printf("\n\n");
    printf("The copied string entered by you (i.e. 'SR_chArrayCopy[]') is: \n\n");
    printf("%s\n", SR_chArrayCopy);

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