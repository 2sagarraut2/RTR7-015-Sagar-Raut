#include <stdio.h>
#include <ctype.h>

#define SR_MAX_STRING_LENGTH 512

#define SPACE ' '
#define FULL_STOP '.'
#define COMMA ','
#define EXCLAMATION '!'
#define QUESTION_MARK '?'

int main(void)
{
    int MyStrlen(char[]);
    char myToUpper(char);

    char SR_chArray[SR_MAX_STRING_LENGTH], chArrayCapitalize[SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int i, j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArray, SR_MAX_STRING_LENGTH, stdin);

    SR_iStringLength = MyStrlen(SR_chArray);
    j = 0;

    for (i = 0; i < SR_iStringLength; i++)
    {
        if (i == 0)
        {
            chArrayCapitalize[j] = toupper(SR_chArray[i]);
        }
        else if (SR_chArray[i] == SPACE)
        {
            chArrayCapitalize[j] = SR_chArray[i];
            chArrayCapitalize[j + 1] = myToUpper(SR_chArray[i + 1]);

            j++;
            i++;
        }
        else if ((SR_chArray[i] == FULL_STOP) || (SR_chArray[i] == COMMA) || (SR_chArray[i] == EXCLAMATION) || (SR_chArray[i] == QUESTION_MARK) && (SR_chArray[i] != SPACE))
        {
            chArrayCapitalize[j] = SR_chArray[i];
            chArrayCapitalize[j + 1] = SPACE;
            chArrayCapitalize[j + 2] = myToUpper(SR_chArray[i + 1]);

            j = j + 2;
            i++;
        }
        else
        {
            chArrayCapitalize[j] = SR_chArray[i];
        }

        j++;
    }

    chArrayCapitalize[j] = '\0';

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s\n", SR_chArray);

    printf("\n\n");
    printf("String after capitalization of every first word is \n");
    printf("%s\n", chArrayCapitalize);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int SR_stringLength = 0;

    for (j = 0; j < SR_MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
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

char myToUpper(char SR_ch)
{
    int SR_num;
    int c;

    SR_num = 'a' - 'A';

    if ((int)SR_ch >= 97 && (int)SR_ch <= 122)
    {
        c = (int)SR_ch - SR_num;
        return ((char)c);
    }
    else
    {
        return (SR_ch);
    }
}