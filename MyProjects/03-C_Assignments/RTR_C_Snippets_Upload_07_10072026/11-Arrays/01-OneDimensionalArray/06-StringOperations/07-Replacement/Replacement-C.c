#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);
    void MyStrcpy(char SR_str_destination[], char str_source[]);

    char SR_chArrayOriginal[SR_MAX_STRING_LENGTH], SR_chArrayVowelsReplaced[SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int i;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArrayOriginal, SR_MAX_STRING_LENGTH, stdin);

    MyStrcpy(SR_chArrayVowelsReplaced, SR_chArrayOriginal);

    SR_iStringLength = MyStrlen(SR_chArrayVowelsReplaced);

    for (i = 0; i < SR_iStringLength; i++)
    {
        switch (SR_chArrayVowelsReplaced[i])
        {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            SR_chArrayVowelsReplaced[i] = '*';
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