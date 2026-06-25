#include <stdio.h>

int main()
{

    // variables
    int a;

    printf("\n\n");

    a = 5;
    if (a)
    {
        printf("if-block-1:  'A' exists and has value = %d !!!\n\n", a);
    }

    a = -5;
    if (a)
    {
        printf("if-block-2: 'A' exists and has value = %d !!!\n\n", a);
    }

    a = 0;
    if (a)
    {
        printf("if-block-3: 'A' exis and has value %d!!!", a);
    }

    printf("All three if-statements are done!!!\n\n");

    return 0;
}