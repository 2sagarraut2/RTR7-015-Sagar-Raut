#include <stdio.h>
#include <string.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    char *SR_customStrlen(char *str);

    char SR_chArrayOriginal[SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter a string\n\n");
    fgets(SR_chArrayOriginal, SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("The original string entered by you is\n\n");
    printf("%s\n", SR_chArrayOriginal);

    printf("\n\n");
    printf("The reversed string is \n\n");
    printf("%s\n", SR_customStrlen(SR_chArrayOriginal));

    printf("\n\n--End--\n\n");
    return (0);
}

char *SR_customStrlen(char *str)
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