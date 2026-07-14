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

    if ((SR_ch == 'A' || SR_ch == 'a') || (SR_ch == 'E' || SR_ch == 'e') || (SR_ch == 'I' || SR_ch == 'i') || (SR_ch == 'O' || SR_ch == 'o') || (SR_ch == 'U' || SR_ch == 'u'))
    {
        printf("Character %c entered by you is a vowel \n\n", SR_ch);
    }
    else
    {
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
    }

    return 0;
}