#include <stdio.h>
#include <string.h>

#define MAX_STING_LENGTH 512

int main(void)
{
    char chArrayOriginal[MAX_STING_LENGTH], chArrayCopy[MAX_STING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(chArrayOriginal, MAX_STING_LENGTH, stdin);

    strcpy(chArrayCopy, chArrayOriginal);

    printf("\n\n");
    printf("The original string entered by you (i.e. 'chArrayOriginal[]') is \n\n");
    printf("%s\n\n", chArrayOriginal);

    printf("\n\n");
    printf("The copied string (i.e.: 'chArrayCopy[]') is: \n\n");
    printf("%s\n", chArrayCopy);

    printf("\n\n--End--\n\n");
    return (0);
}