#include <stdio.h>
#include <string.h>

#define SR_SR_MAX_STRING_LENGTH 12

int main(void)
{
    char SR_chArray[SR_SR_MAX_STRING_LENGTH];
    int isStringLength = 0;

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(SR_chArray, SR_SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String Entered by you is :\n\n");
    printf("%s\n", SR_chArray);

    printf("\n\n");
    isStringLength = strlen(SR_chArray);
    printf("Length of string is %d characters \n", isStringLength);

    printf("\n\n--End--\n\n");
    return (0);
}