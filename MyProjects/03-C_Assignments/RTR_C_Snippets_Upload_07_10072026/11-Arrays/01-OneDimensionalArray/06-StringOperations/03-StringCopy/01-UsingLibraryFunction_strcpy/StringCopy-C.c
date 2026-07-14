#include <stdio.h>
#include <string.h>

#define MAX_STING_LENGTH 512

int main(void)
{
    char SR_chArrayOriginal[MAX_STING_LENGTH], SR_chArrayCopy[MAX_STING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(SR_chArrayOriginal, MAX_STING_LENGTH, stdin);

    strcpy(SR_chArrayCopy, SR_chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you (i.e. 'SR_chArrayOriginal[]') is \n\n");
    printf("%s\n\n", SR_chArrayOriginal);

    printf("\n\n");
    printf("The copied string (i.e.: 'SR_chArrayCopy[]') is: \n\n");
    printf("%s\n", SR_chArrayCopy);

    printf("\n\n--End--\n\n");
    return (0);
}