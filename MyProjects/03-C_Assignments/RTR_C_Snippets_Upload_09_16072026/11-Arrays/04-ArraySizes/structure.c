#include <stdio.h>

typedef struct
{
    int num;
    int table[10];
} printNum;

printNum numTables[10];

int main(void)
{
    int numElements = sizeof(numTables) / sizeof(numTables[0]);

    for (int i = 0; i < numElements; i++)
    {
        numTables[i].num = i + 1;
        for (int j = 0; j < 10; j++)
        {
            numTables[i].table[j] = (numTables[i].num * (j + 1));
        }
    }

    for (int i = 0; i < sizeof(numTables) / sizeof(numTables[0]); i++)
    {
        printf("Number: %d\n", numTables[i].num = i + 1);
        for (int j = 0; j < sizeof(numTables[0]) / sizeof(numTables[0].table[0]); j++)
        {
            printf("%d\n", numTables[i].table[j] = (numTables[i].num * (j + 1)));
        }
        printf("\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}