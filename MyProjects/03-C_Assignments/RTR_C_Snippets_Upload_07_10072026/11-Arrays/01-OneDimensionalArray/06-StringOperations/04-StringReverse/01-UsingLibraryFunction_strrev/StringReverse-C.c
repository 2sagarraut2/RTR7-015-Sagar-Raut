#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    char *customStrlen(char *str);

    char chArrayOriginal[MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(chArrayOriginal, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("The original string entered by you is\n\n");
    printf("%s\n", chArrayOriginal);

    printf("\n\n");
    printf("The reversed string is \n\n");
    printf("%s\n", customStrlen(chArrayOriginal));

    printf("\n\n--End--\n\n");
    return (0);
}

char *customStrlen(char *str)
{

    if (!str)
        return NULL;

    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}