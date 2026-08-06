#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{

    int MyStrLength(char *);

    char *chArray = NULL;
    int stringLength = 0;

    printf("\n\n");
    chArray = (char *)malloc(sizeof(char) * MAX_STRING_LENGTH);

    if (chArray == NULL)
    {
        printf("Failed to aloocate memory for chArray\n");
        exit(0);
    }
    else
    {
        printf("Memoy allocated for chArray\n\n");
    }

    printf("Enter a string\n");
    scanf("%s", chArray);

    printf("\n\n");
    printf("String entered is:\n");
    printf("%s\n", chArray);

    printf("\n\n");
    stringLength = MyStrLength(chArray);
    printf("Length of string entered by you is %d\n", stringLength);

    if (chArray)
    {
        free(chArray);
        chArray = NULL;
    }

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrLength(char *str)
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