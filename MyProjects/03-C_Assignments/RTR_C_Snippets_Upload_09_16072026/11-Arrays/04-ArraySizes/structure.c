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

    for (int SR_i = 0; SR_i < numElements; SR_i++)
    {
        numTables[SR_i].num = SR_i + 1;
        for (int SR_j = 0; SR_j < 10; SR_j++)
        {
            numTables[SR_i].table[SR_j] = (numTables[SR_i].num * (SR_j + 1));
        }
    }

    for (int SR_i = 0; SR_i < sizeof(numTables) / sizeof(numTables[0]); SR_i++)
    {
        printf("Number: %d\n", numTables[SR_i].num = SR_i + 1);
        for (int SR_j = 0; SR_j < sizeof(numTables[0]) / sizeof(numTables[0].table[0]); SR_j++)
        {
            printf("%d\n", numTables[SR_i].table[SR_j] = (numTables[SR_i].num * (SR_j + 1)));
        }
        printf("\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}