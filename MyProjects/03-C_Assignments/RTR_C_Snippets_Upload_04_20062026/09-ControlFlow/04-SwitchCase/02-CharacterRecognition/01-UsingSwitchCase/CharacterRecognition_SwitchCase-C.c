#include <stdio.h>
#include <ctype.h>

#define CHAR_ALPHABET_UPPER_CASE_BEGINNING 65
#define CHAR_ALPHABET_UPPER_CASE_ENDING 90

#define CHAR_ALPHABET_LOWER_CASE_BEGINNING 97
#define CHAR_ALPHABET_LOWER_CASE_ENDING 122

#define CHAR_DEGIT_BEGINNING 48
#define CHAR_DEGIT_ENDING 57

int main()
{
    char SR_ch;
    int ch_value;

    printf("\n\n");

    printf("Enter character\n");
    SR_ch = getchar();

    switch (SR_ch)
    {
    case 'A':
    case 'a':

    case 'E':
    case 'e':

    case 'I':
    case 'i':

    case 'O':
    case 'o':

    case 'U':
    case 'u':
        printf("Character %c entered by you is a vowel \n\n", SR_ch);
        break;
    default:
        ch_value = (int)SR_ch;

        if ((ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING) || (ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING))
        {
            printf("Character %c entered by you is a consonant \n\n", SR_ch);
        }
        else if (ch_value >= CHAR_DEGIT_BEGINNING && ch_value <= CHAR_DEGIT_ENDING)
        {
            printf("Character %c entered by you is a digit\n\n", SR_ch);
        }
        else
        {
            printf("Character %c entered by you is a special character\n\n", SR_ch);
        }
        break;
    }
    printf("Switch case block executed\n");

    return 0;
}