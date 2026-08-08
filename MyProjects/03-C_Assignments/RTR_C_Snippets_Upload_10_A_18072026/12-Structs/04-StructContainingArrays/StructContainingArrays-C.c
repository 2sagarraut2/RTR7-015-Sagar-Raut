#include <stdio.h>
#include <string.h>

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
    dataOne.fArray[4] = 6.1f;

    printf("\n\n");
    printf("Enter %d Integers: \n\n", INT_ARRAY_SIZE);
    for (SR_i = 0; SR_i < INT_ARRAY_SIZE; SR_i++)
    {
        scanf("%d", &dataOne.iArray[SR_i]);
    }

    for (SR_i = 0; SR_i < CHAR_ARRAY_SIZE; SR_i++)
    {
        dataTwo.cArray[SR_i] = (char)(SR_i + ALPHABET_BEINNING);
    }

    strcpy(dataTwo.strArray[0], "Welcome!! ");
    strcpy(dataTwo.strArray[1], "This ");
    strcpy(dataTwo.strArray[2], "Is ");
    strcpy(dataTwo.strArray[3], "ASTROMEDICOMP's ");
    strcpy(dataTwo.strArray[4], "Real ");
    strcpy(dataTwo.strArray[5], "Time ");
    strcpy(dataTwo.strArray[6], "Rendering ");
    strcpy(dataTwo.strArray[7], "Batch ");
    strcpy(dataTwo.strArray[8], "of ");
    strcpy(dataTwo.strArray[9], "2026-27.");

    printf("\n\n");
    printf("Members of struct dataOne along with their assigned values \n\n");

    printf("\n\n");
    printf("Integer Array (dataOne.iArray[]) : \n\n");
    for (SR_i = 0; SR_i < INT_ARRAY_SIZE; SR_i++)
    {
        printf("dataOne.iArray[%d] = %d\n", SR_i, dataOne.iArray[SR_i]);
    }

    printf("\n\n");
    printf("Float Array (dataOne.fArray[]) : \n\n");
    for (SR_i = 0; SR_i < FLOAT_ARRAY_SIZE; SR_i++)
    {
        printf("dataOne.fArray[%d] = %f\n", SR_i, dataOne.fArray[SR_i]);
    }

    printf("\n\n");
    printf("Members of struct dataTwo along with their assigned values \n\n");

    printf("\n\n");
    printf("Character Array (dataTwo.cArray[]) : \n\n");
    for (SR_i = 0; SR_i < CHAR_ARRAY_SIZE; SR_i++)
    {
        printf("dataOne.cArray[%d] = %c\n", SR_i, dataTwo.cArray[SR_i]);
    }

    printf("\n\n");
    printf("String Array (dataTwo.strArray[]) : \n\n");
    for (SR_i = 0; SR_i < NUM_STRINGS; SR_i++)
    {
        printf("%s\n", dataTwo.strArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}