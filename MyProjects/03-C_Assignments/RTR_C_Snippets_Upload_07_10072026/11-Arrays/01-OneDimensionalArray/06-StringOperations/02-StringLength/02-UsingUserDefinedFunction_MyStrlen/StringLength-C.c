#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{

    int MyStrlen(char[]);

    char chArray[MAX_STRING_LENGTH];
    int iStringLength = 0;

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", chArray);

    printf("\n\n");
    iStringLength = MyStrlen(chArray);
    printf("Length of string is = %d characters\n\n", iStringLength);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int string_length = 0;

    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
        {
            break;
        }
        else
        {
            string_length++;
        }
    }

    return (string_length);
}