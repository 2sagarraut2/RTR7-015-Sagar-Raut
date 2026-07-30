#include <stdio.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char SR_chArray[SR_MAX_STRING_LENGTH], SR_chArraySpacesRemoved[SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int SR_i, SR_j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArray, SR_MAX_STRING_LENGTH, stdin);

    SR_iStringLength = MyStrlen(SR_chArray);
    SR_j = 0;

    for (SR_i = 0; SR_i < SR_iStringLength; SR_i++)
    {
        if (SR_chArray[SR_i] == ' ')
        {
            continue;
        }
        else
        {
            SR_chArraySpacesRemoved[SR_j] = SR_chArray[SR_i];
            SR_j++;
        }
    }

    SR_chArraySpacesRemoved[SR_j] = '\0';

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", SR_chArray);

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", SR_chArraySpacesRemoved);

    printf("\n\n--End--\n\n");
    return (0);
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