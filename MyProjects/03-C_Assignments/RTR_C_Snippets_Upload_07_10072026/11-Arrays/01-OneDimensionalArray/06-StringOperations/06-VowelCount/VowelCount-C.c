#include <stdio.h>

#define MAX_STRING_LENGTH 512

int main(void)
{
    int MyStrlen(char str[]);

    char chArray[MAX_STRING_LENGTH];
    int iStringLength;
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    int i;

    printf("ENter a string\n\n");
    fgets(chArray, MAX_STRING_LENGTH, stdin);

    printf("\n\n");
    printf("String entered by you is\n");
    printf("%s", chArray);

    iStringLength = MyStrlen(chArray);

    for (i = 0; i < iStringLength; i++)
    {
        switch (chArray[i])
        {
        case 'A':
        case 'a':
            countA++;
            break;

        case 'E':
        case 'e':
            countE++;
            break;

        case 'I':
        case 'i':
            countI++;
            break;

        case 'O':
        case 'o':
            countO++;
            break;

        case 'U':
        case 'u':
            countU++;
            break;

        default:
            break;
        }
    }

    printf("\n\n");
    printf("In the string entered by you the vowels and the number of their occurences are aas follows:\n\n");
    printf("A or a has occurred %d times\n", countA);
    printf("E or e has occurred %d times\n", countE);
    printf("I or i has occurred %d times\n", countI);
    printf("O or o has occurred %d times\n", countO);
    printf("U or u has occurred %d times\n", countU);

    printf("\n\n--End--\n\n");
    return (0);
}

int MyStrlen(char str[])
{
    int j;
    int StringLength = 0;

    for (j = 0; j < MAX_STRING_LENGTH; j++)
    {
        if (str[j] == '\0')
        {
            break;
        }
        else
        {
            StringLength = StringLength + 1;
        }
    }

    return (StringLength);
}