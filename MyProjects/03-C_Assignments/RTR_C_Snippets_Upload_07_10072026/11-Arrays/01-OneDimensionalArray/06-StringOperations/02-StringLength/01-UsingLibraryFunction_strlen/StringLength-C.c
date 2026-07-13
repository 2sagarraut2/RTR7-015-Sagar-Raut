#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 12

int main(void)
{
    char chArray[MAX_STRING_LENGTH];
    int isStringLength = 0;

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String Entered by you is :\n\n");
    printf("%s\n", chArray);

    printf("\n\n");
    isStringLength = strlen(chArray);
    printf("Length of string is %d characters \n", isStringLength);

    printf("\n\n--End--\n\n");
    return (0);
}