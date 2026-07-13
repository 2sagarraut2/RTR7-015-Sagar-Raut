#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);
    void MyStrcpy(char str_destination[], char str_source[]);

    char chArrayOriginal[MAX_STRING_LENGTH], chArrayVowelsReplaced[MAX_STRING_LENGTH];
    int iStringLength;
    int i;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(chArrayOriginal, MAX_STRING_LENGTH, stdin);

    MyStrcpy(chArrayVowelsReplaced, chArrayOriginal);

    iStringLength = MyStrlen(chArrayVowelsReplaced);

    for (i = 0; i < iStringLength; i++)
    {
        switch (chArrayVowelsReplaced[i])
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
            chArrayVowelsReplaced[i] = '*';
            break;
        default:
            break;
        }
    }

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", chArrayOriginal);

    printf("\n\n");
    printf("String after replacement of vowels with * is\n");
    printf("%s\n", chArrayVowelsReplaced);

    printf("\n\n--End--\n\n");
    return (0);
}

void MyStrcpy(char str_destination[], char str_source[])
{
    int MyStrlen(char[]);

    int iStringLength = 0;
    int j;

    iStringLength = MyStrlen(str_source);
    for (j = 0; j < iStringLength; j++)
    {
        str_destination[j] = str_source[j];
    }

    str_destination[j] = '\0';
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