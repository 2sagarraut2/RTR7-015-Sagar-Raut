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
    int SR_i, SR_j;

    printf("\n\n");
    printf("ENter a string\n\n");
    fgets(SR_chArray, SR_MAX_STRING_LENGTH, stdin);

    SR_iStringLength = MyStrlen(SR_chArray);
    SR_j = 0;

    for (SR_i = 0; SR_i < SR_iStringLength; SR_i++)
    {
        if (SR_i == 0)
        {
            chArrayCapitalize[SR_j] = toupper(SR_chArray[SR_i]);
        }
        else if (SR_chArray[SR_i] == SPACE)
        {
            chArrayCapitalize[SR_j] = SR_chArray[SR_i];
            chArrayCapitalize[SR_j + 1] = myToUpper(SR_chArray[SR_i + 1]);

            SR_j++;
            SR_i++;
        }
        else if ((SR_chArray[SR_i] == FULL_STOP) || (SR_chArray[SR_i] == COMMA) || (SR_chArray[SR_i] == EXCLAMATION) || (SR_chArray[SR_i] == QUESTION_MARK) && (SR_chArray[SR_i] != SPACE))
        {
            chArrayCapitalize[SR_j] = SR_chArray[SR_i];
            chArrayCapitalize[SR_j + 1] = SPACE;
            chArrayCapitalize[SR_j + 2] = myToUpper(SR_chArray[SR_i + 1]);

            SR_j = SR_j + 2;
            SR_i++;
        }
        else
        {
            chArrayCapitalize[SR_j] = SR_chArray[SR_i];
        }

        SR_j++;
    }

    chArrayCapitalize[SR_j] = '\0';

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

char myToUpper(char SR_ch)
{
    int SR_num;
    int SR_c;

    SR_num = 'a' - 'A';

    if ((int)SR_ch >= 97 && (int)SR_ch <= 122)
    {
        SR_c = (int)SR_ch - SR_num;
        return ((char)SR_c);
    }
    else
    {
        return (SR_ch);
    }
}