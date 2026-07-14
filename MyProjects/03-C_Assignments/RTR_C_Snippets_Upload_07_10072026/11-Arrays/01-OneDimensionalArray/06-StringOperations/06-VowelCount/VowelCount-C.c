#include <stdio.h>

#define SR_SR_MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char SR_chArray[SR_SR_MAX_STRING_LENGTH];
    int SR_iStringLength;
    int SR_countA = 0, SR_countE = 0, SR_countI = 0, SR_countO = 0, SR_countU = 0;
    int i;

    printf("ENter a string\n\n");
    fgets(SR_chArray, SR_SR_MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s", SR_chArray);

    SR_iStringLength = MyStrlen(SR_chArray);

    for (i = 0; i < SR_iStringLength; i++)
    {
        switch (SR_chArray[i])
        {
        case 'A':
        case 'a':
            SR_countA++;
            break;

        case 'E':
        case 'e':
            SR_countE++;
            break;

        case 'I':
        case 'i':
            SR_countI++;
            break;

        case 'O':
        case 'o':
            SR_countO++;
            break;

        case 'U':
        case 'u':
            SR_countU++;
            break;

        default:
            break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you the vowels and the number of their occurences are aas follows:\n\n");
    printf("A or a has occurred %d times\n", SR_countA);
    printf("E or e has occurred %d times\n", SR_countE);
    printf("I or i has occurred %d times\n", SR_countI);
    printf("O or o has occurred %d times\n", SR_countO);
    printf("U or u has occurred %d times\n", SR_countU);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int SR_stringLength = 0;

    for (j = 0; j < SR_SR_MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
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