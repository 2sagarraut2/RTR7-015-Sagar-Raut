#include <stdio.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 512

#define SPACE ' '
#define FULL_STOP '.'
#define COMMA ','
#define EXCLAMATION '!'
#define QUESTION_MARK '?'

int main(void)
{
    int MyStrlen(char[]);
    char myToUpper(char);

    char chArray[MAX_STRING_LENGTH], chArrayCapitalize[MAX_STRING_LENGTH];
    int iStringLength;
    int i, j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    iStringLength = MyStrlen(chArray);
    j = 0;

    for (i = 0; i < iStringLength; i++)
    {
        if (i == 0)
        {
            chArrayCapitalize[j] = toupper(chArray[i]);
        }
        else if (chArray[i] == SPACE)
        {
            chArrayCapitalize[j] = chArray[i];
            chArrayCapitalize[j + 1] = myToUpper(chArray[i + 1]);

            j++;
            i++;
        }
        else if ((chArray[i] == FULL_STOP) || (chArray[i] == COMMA) || (chArray[i] == EXCLAMATION) || (chArray[i] == QUESTION_MARK) && (chArray[i] != SPACE))
        {
            chArrayCapitalize[j] = chArray[i];
            chArrayCapitalize[j + 1] = SPACE;
            chArrayCapitalize[j + 2] = myToUpper(chArray[i + 1]);

            j = j + 2;
            i++;
        }
        else
        {
            chArrayCapitalize[j] = chArray[i];
        }

        j++;
    }

    chArrayCapitalize[j] = '\0';

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", chArray);

    printf("\n\n");
    printf("String after capitalization of every first word is \n");
    printf("%s\n", chArrayCapitalize);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int stringLength = 0;

    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
        {
            break;
        }
        else
        {
            stringLength++;
        }
    }

    return (stringLength);
}

char myToUpper(char ch)
{
    int num;
    int c;

    num = 'a' - 'A';

    if ((int)ch >= 97 && (int)ch <= 122)
    {
        c = (int)ch - num;
        return ((char)c);
    }
    else
    {
        return (ch);
    }
}