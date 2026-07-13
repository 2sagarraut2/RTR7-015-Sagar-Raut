#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    char chArrayOne[MAX_STRING_LENGTH], chArrayTwo[MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter first string\n");
    fgets(chArrayOne, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("Enter second string\n");
    fgets(chArrayTwo, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("***Before concatination***\n\n");

    printf("\n\n");
    printf("The original first string entered by you is\n");
    printf("%s\n", chArrayOne);

    printf("\n\n");
    printf("The origianal second string entered by you is\n");
    printf("%s\n", chArrayTwo);

    strcat(chArrayOne, chArrayTwo);

    printf("\n\n");
    printf("***After concatination***\n\n");

    printf("\n\n");
    printf("chArrayOne[] is\n");
    printf("%s\n", chArrayOne);

    printf("\n\n");
    printf("chArrayTwo[] is\n");
    printf("%s\n", chArrayTwo);

    printf("\n\n--End--\n\n");
    return (0);
}