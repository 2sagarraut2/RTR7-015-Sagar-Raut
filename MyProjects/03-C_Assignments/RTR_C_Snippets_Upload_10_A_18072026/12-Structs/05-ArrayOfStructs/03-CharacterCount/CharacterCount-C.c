#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SR_MAX_STRING_LENGTH 1024
#define SR_SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS sizeof(characterAndCount)
#define SR_SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS sizeof(characterAndCount[0])
#define SR_NUM_ELEMENTS_IN_ARRAY (SR_SIZE_OF_ENTIRE_ARRAY_OF_STRUCTS / SR_SIZE_OF_ONE_STRUCT_FROM_THE_ARRAY_OF_STRUCTS)

struct characterAndCount
{
    char ch;
    int chCount;
} characterAndCount[] = {
    {'A', 0},
    {'B', 0},
    {'C', 0},
    {'D', 0},
    {'E', 0},
    {'F', 0},
    {'G', 0},
    {'H', 0},
    {'I', 0},
    {'J', 0},
    {'K', 0},
    {'L', 0},
    {'M', 0},
    {'N', 0},
    {'O', 0},
    {'P', 0},
    {'Q', 0},
    {'R', 0},
    {'S', 0},
    {'T', 0},
    {'U', 0},
    {'V', 0},
    {'W', 0},
    {'X', 0},
    {'Y', 0},
    {'Z', 0}};

int main(void)
{
    char str[SR_MAX_STRING_LENGTH];
    int SR_i, SR_j, SR_actualStringLength = 0;

    printf("\n\n");
    printf("Enter a string\n");
    fgets(str, SR_MAX_STRING_LENGTH, stdin);

    SR_actualStringLength = strlen(str);

    printf("\n\n");
    printf("The string you entered is :\n\n");
    printf("%s\n\n", str);

    for (SR_i = 0; SR_i < SR_actualStringLength; SR_i++)
    {
        for (SR_j = 0; SR_j < SR_NUM_ELEMENTS_IN_ARRAY; SR_j++)
        {
            str[SR_i] = toupper(str[SR_i]);

            // printf("%c - %c\n", str[SR_i], characterAndCount[SR_j].ch);

            if (str[SR_i] == characterAndCount[SR_j].ch)
            {
                // printf("inside if\n");
                characterAndCount[SR_j].chCount++;
            }
        }
    }

    printf("\n\n");
    printf("The number of occurances of all characters from the Alphabet as follows:\n");
    for (SR_i = 0; SR_i < SR_NUM_ELEMENTS_IN_ARRAY; SR_i++)
    {
        printf("Character %c = %d\n", characterAndCount[SR_i].ch, characterAndCount[SR_i].chCount);
    }

    printf("\n\n--End--\n\n");
    return (0);
}