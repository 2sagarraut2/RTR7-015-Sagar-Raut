#include <stdio.h>

struct MyNumer
{
    int SR_num;
    int SR_numTable[10];
};

struct NumTables
{
    struct MyNumer SR_a;
    struct MyNumer SR_b;
    struct MyNumer SR_c;
};

int main(void)
{
    struct NumTables tables;
    int SR_i = 0;

    tables.SR_a.SR_num = 5;
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        tables.SR_a.SR_numTable[SR_i] = tables.SR_a.SR_num * (SR_i + 1);
    }
    printf("\n\n");
    printf("Table of %d :\n\n", tables.SR_a.SR_num);
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("%d * %d = %d\n", tables.SR_a.SR_num, (SR_i + 1), tables.SR_a.SR_numTable[SR_i]);
    }

    tables.SR_b.SR_num = 6;
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        tables.SR_b.SR_numTable[SR_i] = tables.SR_b.SR_num * (SR_i + 1);
    }
    printf("\n\n");
    printf("Table of %d :\n\n", tables.SR_b.SR_num);
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("%d * %d = %d\n", tables.SR_b.SR_num, (SR_i + 1), tables.SR_b.SR_numTable[SR_i]);
    }

    tables.SR_c.SR_num = 7;
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        tables.SR_c.SR_numTable[SR_i] = tables.SR_c.SR_num * (SR_i + 1);
    }
    printf("\n\n");
    printf("Table of %d :\n\n", tables.SR_c.SR_num);
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("%d * %d = %d\n", tables.SR_c.SR_num, (SR_i + 1), tables.SR_c.SR_numTable[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}