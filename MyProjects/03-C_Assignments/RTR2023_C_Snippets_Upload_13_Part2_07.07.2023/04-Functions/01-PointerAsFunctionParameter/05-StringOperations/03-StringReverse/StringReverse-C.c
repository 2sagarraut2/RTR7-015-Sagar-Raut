#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int SR_MyStrLength(char *);
    void SR_MyStrReverse(char *, char *);

    char *SR_chArrayOriginal = NULL, *SR_chArrayReversed = NULL;
    int OriginalStringLength = 0;

    printf("\n\n");
    SR_chArrayOriginal = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (SR_chArrayOriginal == NULL)
    {
        printf("Failed to aloocate memory for chArray\n");
        exit(0);
    }

    printf("Enter a string\n");
    scanf("%s", SR_chArrayOriginal);

    OriginalStringLength = SR_MyStrLength(SR_chArrayOriginal);

    printf("Length of string entered by you is %d\n", OriginalStringLength);

    SR_chArrayReversed = (char *)malloc(sizeof(char) * OriginalStringLength);

    if (SR_chArrayReversed == NULL)
    {
        printf("Failed to aloocate memory for SR_chArrayReversed\n");
        exit(0);
    }

    SR_MyStrReverse(SR_chArrayReversed, SR_chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you is \n\n");
    printf("%s", SR_chArrayOriginal);
    printf("\n\n");

    printf("\n\n");
    printf("The reversed string is \n\n");
    printf("%s", SR_chArrayReversed);
    printf("\n\n");

    if (SR_chArrayReversed)
    {
        free(SR_chArrayReversed);
        SR_chArrayReversed = NULL;
        printf("Memory allocate for SR_chArrayReversed has been released\n");
    }

    if (SR_chArrayOriginal)
    {
        free(SR_chArrayOriginal);
        SR_chArrayOriginal = NULL;
        printf("Memory allocate for SR_chArrayOriginal has been released\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void SR_MyStrReverse(char *strDestination, char *strSource)
{
    int SR_MyStrLength(char *);

    int iStringLength = 0;
    int SR_i = 0, SR_j = 0, len = 0;

    iStringLength = SR_MyStrLength(strSource);

    len = iStringLength - 1;

    for (SR_i = 0, SR_j = len; SR_i < iStringLength, SR_j >= 0; SR_i++, SR_j--)
    {
        *(strDestination + SR_i) = *(strSource + SR_j);
    }

    *(strDestination + SR_i) = '\0';
}

int SR_MyStrLength(char *str)
{
    int length = 0;

    while (*str != '\0')
    {
        // printf("%c - %d\n", str[k], length);
        length++;
        str++;
    }

    return (length);
}