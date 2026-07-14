#include <stdio.h>

#define SR_SR_MAX_STRING_LENGTH 512

int main(void)
{
    char SR_chArray[SR_SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(SR_chArray, SR_SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", SR_chArray);

    printf("\n\n--End--\n\n");
    return (0);
}