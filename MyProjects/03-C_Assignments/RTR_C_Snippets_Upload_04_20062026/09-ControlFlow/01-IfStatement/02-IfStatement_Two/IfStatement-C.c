#include <stdio.h>

int main()
{

    // variables
    int age;

    printf("\n\n");

    printf("Enter Age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("Yu are eligible for voting\n");
    }

    return 0;
}