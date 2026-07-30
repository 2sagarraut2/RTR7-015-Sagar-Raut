#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{

    int MyStrlen(char[]);

    char SR_chArray[SR_MAX_STRING_LENGTH];
    int SR_iStringLength = 0;

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(SR_chArray, SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is: \n\n");
    printf("%s\n", SR_chArray);

    printf("\n\n");
    SR_iStringLength = MyStrlen(SR_chArray);
    printf("Length of string is = %d characters\n\n", SR_iStringLength);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int SR_j;
    int string_length = 0;

    for (SR_j = 0; SR_j < SR_MAX_STRING_LENGTH; SR_j++)
    {
        if (str[SR_j] == '\0')
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