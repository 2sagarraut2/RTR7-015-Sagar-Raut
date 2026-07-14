#include <stdio.h>

#define SR_SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char SR_chArray[SR_SR_MAX_STRING_LENGTH], SR_chArraySpacesRemoved[SR_SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int i, j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArray, SR_SR_MAX_STRING_LENGTH, stdin);

    SR_iStringLength = MyStrlen(SR_chArray);
    j = 0;

    for (i = 0; i < SR_iStringLength; i++)
    {
        if (SR_chArray[i] == ' ')
        {
            continue;
        }
        else
        {
            SR_chArraySpacesRemoved[j] = SR_chArray[i];
            j++;
        }
    }

    SR_chArraySpacesRemoved[j] = '\0';

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