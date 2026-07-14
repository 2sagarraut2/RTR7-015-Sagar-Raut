#include <stdio.h>

#define SR_SR_MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrcpy(char[], char[]);

    char SR_chArrayOriginal[SR_SR_MAX_STRING_LENGTH], SR_chArrayCopy[SR_SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(SR_chArrayOriginal, SR_SR_MAX_STRING_LENGTH, stdin);

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
    int j;

    SR_iStringLength = MyStrlen(str_source);
    for (j = 0; j < SR_iStringLength; j++)
    {
        SR_str_destination[j] = str_source[j];
    }

    SR_str_destination[j] = '\0';
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