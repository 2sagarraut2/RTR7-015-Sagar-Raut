#include <stdio.h>
#include <string.h>

#define SR_MAX_STRING_LENGTH 512

int main(void)
{
    void MyStrCat(char[], char[]);

    char SR_chArrayOne[SR_MAX_STRING_LENGTH], SR_chArrayTwo[SR_MAX_STRING_LENGTH];

    printf("\n\n");
    printf("Enter first string\n");
    fgets(SR_chArrayOne, SR_MAX_STRING_LENGTH, stdin);

    SR_chArrayOne[strlen(SR_chArrayOne) - 1] = '\0';

    printf("\n\n");
    printf("Enter second string\n");
    fgets(SR_chArrayTwo, SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("***Before concatination***\n\n");

    printf("\n\n");
    printf("The original first string entered by you is\n");
    printf("%s\n", SR_chArrayOne);

    printf("\n\n");
    printf("The origianal second string entered by you is\n");
    printf("%s\n", SR_chArrayTwo);

    MyStrCat(SR_chArrayOne, SR_chArrayTwo);

    printf("\n\n");
    printf("***After concatination***\n\n");

    printf("\n\n");
    printf("SR_chArrayOne[] is\n");
    printf("%s\n", SR_chArrayOne);

    printf("\n\n");
    printf("SR_chArrayTwo[] is\n");
    printf("%s\n", SR_chArrayTwo);

    printf("\n\n--End--\n\n");
    return (0);
}

void MyStrCat(char strDestination[], char strSource[])
{
    int MyStrlen(char[]);

    int iStringLengthSource = 0, iStringLengthDestination = 0;
    int SR_i, SR_j;

    iStringLengthSource = MyStrlen(strSource);
    iStringLengthDestination = MyStrlen(strDestination);

    for (SR_i = iStringLengthDestination, SR_j = 0; SR_j < iStringLengthSource; SR_i++, SR_j++)
    {
        strDestination[SR_i] = strSource[SR_j];
    }

    strDestination[SR_i] = '\0';
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
            SR_stringLength = SR_stringLength + 1;
        }
    }

    return (SR_stringLength);
}