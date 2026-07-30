#include <stdio.h>

#define INT_ARRAY_SIZE 10
#define FLOAT_ARRAY_SIZE 5
#define CHAR_ARRAY_SIZE 26

#define NUM_STRINGS 10
#define MAX_CHARACTER_PER_STRING 20

#define ALPHABET_BEINNING 65

typedef struct
{
    int iArray[INT_ARRAY_SIZE];
    float fArray[FLOAT_ARRAY_SIZE];
} MyDataOne;

typedef struct
{
    char cArray[CHAR_ARRAY_SIZE];
    char strArray[NUM_STRINGS][MAX_CHARACTER_PER_STRING];
} MyDataTwo;

int main(void)
{
    MyDataOne dataOne;
    MyDataTwo dataTwo;
    int SR_i;

    dataOne.fArray[0] = 1.1f;
    dataOne.fArray[1] = 2.5f;
    dataOne.fArray[2] = 3.5f;
    dataOne.fArray[3] = 4.5f;
    dataOne.fArray[4] = 6.5f;

    printf("\n\n--End--\n\n");
    return (0);
}