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
    char ch;
    int ch_value;

    printf("\n\n");

    printf("Enter character\n");
    ch = getchar();

    if ((ch == 'A' || ch == 'a') || (ch == 'E' || ch == 'e') || (ch == 'I' || ch == 'i') || (ch == 'O' || ch == 'o') || (ch == 'U' || ch == 'u'))
    {
        printf("Character %c entered by you is a vowel \n\n", ch);
    }
    else
    {
        ch_value = (int)ch;

        if ((ch_value >= CHAR_ALPHABET_LOWER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_LOWER_CASE_ENDING) || (ch_value >= CHAR_ALPHABET_UPPER_CASE_BEGINNING && ch_value <= CHAR_ALPHABET_UPPER_CASE_ENDING))
        {
            printf("Character %c entered by you is a consonant \n\n", ch);
        }
        else if (ch_value >= CHAR_DEGIT_BEGINNING && ch_value <= CHAR_DEGIT_ENDING)
        {
            printf("Character %c entered by you is a digit\n\n", ch);
        }
        else
        {
            printf("Character %c entered by you is a special character\n\n", ch);
        }
    }

    return 0;
}