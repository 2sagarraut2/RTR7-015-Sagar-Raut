#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);
    void MyStrcpy(char SR_str_destination[], char str_source[]);

    char SR_chArrayOriginal[SR_MAX_STRING_LENGTH], SR_chArrayVowelsReplaced[SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int SR_i;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArrayOriginal, SR_MAX_STRING_LENGTH, stdin);

    MyStrcpy(SR_chArrayVowelsReplaced, SR_chArrayOriginal);

    SR_iStringLength = MyStrlen(SR_chArrayVowelsReplaced);

    for (SR_i = 0; SR_i < SR_iStringLength; SR_i++)
    {
        switch (SR_chArrayVowelsReplaced[SR_i])
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'SR_i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            SR_chArrayVowelsReplaced[SR_i] = '*';
            break;
        default:
            break;
        }
    }

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", SR_chArrayOriginal);

    printf("\n\n");
    printf("String after replacement of vowels with * is\n");
    printf("%s\n", SR_chArrayVowelsReplaced);

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