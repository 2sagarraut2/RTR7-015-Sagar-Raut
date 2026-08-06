#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int SR_MyStrLength(char *);
    void SR_MyStrCopy(char *, char *);

    char *SR_chArrayOriginal = NULL, *chArrayCopy = NULL;
    int SR_OriginalStringLength = 0;

    printf("\n\n");
    SR_chArrayOriginal = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (SR_chArrayOriginal == NULL)
    {
        printf("Failed to aloocate memory for chArray\n");
        exit(0);
    }

    printf("Enter a string\n");
    scanf("%s", SR_chArrayOriginal);

    SR_OriginalStringLength = SR_MyStrLength(SR_chArrayOriginal);

    printf("Length of string entered by you is %d\n", SR_OriginalStringLength);

    chArrayCopy = (char *)malloc(sizeof(char) * SR_OriginalStringLength);

    if (chArrayCopy == NULL)
    {
        printf("Failed to aloocate memory for chArrayCopy\n");
        exit(0);
    }

    SR_MyStrCopy(chArrayCopy, SR_chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you is \n\n");
    printf("%s", SR_chArrayOriginal);
    printf("\n\n");

    printf("\n\n");
    printf("The copied string is \n\n");
    printf("%s", chArrayCopy);
    printf("\n\n");

    if (chArrayCopy)
    {
        free(chArrayCopy);
        chArrayCopy = NULL;
        printf("Memory allocate for chArrayCopy has been released\n");
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

void SR_MyStrCopy(char *strDestination, char *strSource)
{
    int SR_MyStrLength(char *);

    int iStringLength = 0;
    int j = 0;

    iStringLength = SR_MyStrLength(strSource);

    for (j = 0; j < iStringLength; j++)
    {
        *(strDestination + j) = *(strSource + j);
    }

    *(strDestination + j) = '\0';
}

int SR_MyStrLength(char *str)
{
    int length = 0;
    int k = 0;

    while (*str != '\0')
    {
        // printf("%c - %d\n", str[k], length);
        length++;
        str++;
    }

    return (length);
}