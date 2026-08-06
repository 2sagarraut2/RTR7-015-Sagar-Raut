#include <stdio.h>
#include <stdlib.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    char *SR_ReplaceVowelsWithSymbol(char *);

    char SR_string[SR_MAX_STRING_LENGTH];
    char *SR_replacedString = NULL;

    printf("\n\n");
    printf("Enter String:\n\n");
    fgets(SR_string, SR_MAX_STRING_LENGTH, stdin);

    printf("String entered by you is \n\n");
    printf("%s\n\n", SR_string);

    SR_replacedString = SR_ReplaceVowelsWithSymbol(SR_string);

    if (SR_replacedString == NULL)
    {
        printf("SR_ReplaceVowelsWithSymbol() function has failed! exiting now!!\n\n");
        exit(0);
    }

    printf("\n\n");
    printf("Replaced SR_string is \n\n");
    printf("%s\n\n", SR_replacedString);

    if (SR_replacedString)
    {
        free(SR_replacedString);
        SR_replacedString = NULL;
    }

    printf("\n\n--End--\n\n");
    return (0);
}

char *SR_ReplaceVowelsWithSymbol(char *s)
{
    void SR_MyStrcpy(char *, char *);
    int SR_MyStrlen(char *);

    char *SR_newString = NULL;
    int SR_i;

    SR_newString = (char *)malloc(SR_MyStrlen(s) * sizeof(char));

    if (SR_newString == NULL)
    {
        printf("Failed to allocate memory for new SR_string");
        return (NULL);
    }

    // printf("String from replace is \n\n");
    // printf("%s\n\n", s);

    SR_MyStrcpy(SR_newString, s);

    for (SR_i = 0; SR_i < SR_MyStrlen(SR_newString); SR_i++)
    {
        switch (SR_newString[SR_i])
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            SR_newString[SR_i] = '$';
            break;

        default:
            break;
        }
    }

    return (SR_newString);
}

void SR_MyStrcpy(char *SR_str_destination, char *SR_str_source)
{
    int SR_MyStrlen(char *);

    int SR_iStringLength = 0;
    int SR_j;

    // printf("String from copy 1 is \n\n");
    // printf("%s\n\n", SR_str_source);

    SR_iStringLength = SR_MyStrlen(SR_str_source);

    for (SR_j = 0; SR_j < SR_iStringLength; SR_j++)
    {
        *(SR_str_destination + SR_j) = *(SR_str_source + SR_j);
    }

    // printf("String from copy 2 is \n\n");
    // printf("%s\n\n", SR_str_destination);

    *(SR_str_destination + SR_j) = '\0';
}

int SR_MyStrlen(char *str)
{
    int SR_j;
    int SR_stringLength = 0;

    for (SR_j = 0; SR_j < SR_MAX_STRING_LENGTH; SR_j++)
    {
        if (str[SR_j] == '\0')
        {
            break;
        }
        else
        {
            SR_stringLength++;
        }
    }

    return (SR_stringLength);
}