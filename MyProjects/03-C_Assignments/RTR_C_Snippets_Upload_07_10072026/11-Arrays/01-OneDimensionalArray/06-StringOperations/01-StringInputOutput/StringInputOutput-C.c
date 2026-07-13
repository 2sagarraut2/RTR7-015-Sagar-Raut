#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    char chArray[MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string: \n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is : \n\n");
    printf("%s\n", chArray);

    printf("\n\n--End--\n\n");
    return (0);
}