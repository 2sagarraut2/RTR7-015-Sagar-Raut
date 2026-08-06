#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int SR_MyStrLength(char *);
    void SR_MyStrConcat(char *, char *);

    char *SR_chArrayOne = NULL, *SR_chArrayTwo = NULL;

    printf("\n\n");
    SR_chArrayOne = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (SR_chArrayOne == NULL)
    {
        printf("Failed to aloocate memory for SR_chArrayOne\n");
        exit(0);
    }

    printf("Enter first string\n");
    fgets(SR_chArrayOne, MAX_STRING_LENGTH, stdin);
    SR_chArrayOne[strcspn(SR_chArrayOne, "\n")] = '\0';

    printf("\n\n");
    SR_chArrayTwo = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (SR_chArrayTwo == NULL)
    {
        printf("Failed to aloocate memory for SR_chArrayTwo\n");
        exit(0);
    }

    printf("Enter second string\n");
    fgets(SR_chArrayTwo, MAX_STRING_LENGTH, stdin);
    SR_chArrayTwo[strcspn(SR_chArrayTwo, "\n")] = '\0';

    printf("\n\n");
    printf("BEFORE CONCATINATION\n");
    printf("\n\n");
    printf("The first string entered by you is :\n\n");
    printf("%s", SR_chArrayOne);

    printf("\n\n");
    printf("The  second string entered by you is :\n\n");
    printf("%s", SR_chArrayTwo);

    SR_MyStrConcat(SR_chArrayOne, SR_chArrayTwo);

    printf("\n\n");
    printf("AFTER CONCATINATION\n");
    printf("\n\n");
    printf("The SR_chArrayOne[] entered by you is :\n\n");
    printf("%s", SR_chArrayOne);

    printf("\n\n");
    printf("The SR_chArrayTwo[] entered by you is :\n\n");
    printf("%s", SR_chArrayTwo);
    printf("\n\n");

    if (SR_chArrayTwo)
    {
        free(SR_chArrayTwo);
        SR_chArrayTwo = NULL;
        printf("Memory allocate for SR_chArrayTwo has been released\n");
    }

    if (SR_chArrayOne)
    {
        free(SR_chArrayOne);
        SR_chArrayOne = NULL;
        printf("Memory allocate for SR_chArrayOne has been released\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void SR_MyStrConcat(char *strDestination, char *strSource)
{
    int SR_MyStrLength(char *str);

    int iStringLengthSource = SR_MyStrLength(strSource);
    int iStringLengthDestination = SR_MyStrLength(strDestination);

    int SR_i, SR_j;

    for (SR_i = iStringLengthDestination, SR_j = 0;
         SR_j < iStringLengthSource;
         SR_i++, SR_j++)
    {
        strDestination[SR_i] = strSource[SR_j];
    }

    strDestination[SR_i] = '\0';
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