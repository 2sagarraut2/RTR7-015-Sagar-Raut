#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrcpy(char[], char[]);

    char chArrayOriginal[MAX_STRING_LENGTH], chArrayCopy[MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(chArrayOriginal, MAX_STRING_LENGTH, stdin);

    MyStrcpy(chArrayCopy, chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you (i.e. 'chArrayOriginal[]') is: \n\n");
    printf("%s\n", chArrayOriginal);

    printf("\n\n");
    printf("The copied string entered by you (i.e. 'chArrayCopy[]') is: \n\n");
    printf("%s\n", chArrayCopy);

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