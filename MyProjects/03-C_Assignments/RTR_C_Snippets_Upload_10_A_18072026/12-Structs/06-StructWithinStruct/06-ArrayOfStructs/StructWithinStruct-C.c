#include <stdio.h>

typedef struct
{
    int num;
    int numTable[10];
} MyNumber;

typedef struct
{
    MyNumber n;
} NumTables;

int main(void)
{
    NumTables tables[10];
    int i, j;

    for (i = 0; i < 10; i++)
    {
        tables[i].n.num = (i + 1);
    }

    for (i = 0; i < 10; i++)
    {
        printf("\n\n");
        printf("Table of %d : \n\n", tables[i].n.num);
        for (j = 0; j < 10; j++)
        {
            tables[i].n.numTable[j] = tables[i].n.num * (j + 1);
            printf("%d * %d = %d\n", tables[i].n.num, (j + 1), tables[i].n.numTable[j]);
        }
    }

    printf("\n\n--End--\n\n");
    return (0);
}