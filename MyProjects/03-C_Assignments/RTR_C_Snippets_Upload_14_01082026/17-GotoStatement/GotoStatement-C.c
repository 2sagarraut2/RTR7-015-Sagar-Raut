#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

    char ch, ch_i;
    unsigned int ascii_ch = 0;

    printf("\n\n");
    printf("Enter the first character of first name: \n");
    scanf(" %c", &ch);

    ch = toupper(ch);

    for (ch_i = 'A'; ch_i < +'Z'; ch_i++)
    {
        if (ch == ch_i)
        {
            ascii_ch = (unsigned int)ch;
            goto result_output;
        }
    }

    printf("\n\n");
    printf("Goto statement not executed, so printing \"Hello, World!\n\n");

result_output:
    printf("\n\n");

    if (ascii_ch == 0)
    {
        printf("You must have a unique name! Could not find the charatcer %c in the English Alphabets\n\n", ch);
    }
    else
    {
        printf("Character %c found. It has ASCII value %u.\n", ch, ascii_ch);
    }

    printf("\n\n--End--\n\n");
    return (0);
}