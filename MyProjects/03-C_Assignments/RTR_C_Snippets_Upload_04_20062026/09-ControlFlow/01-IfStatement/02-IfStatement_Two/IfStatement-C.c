#include <stdio.h>

int main()
{

    // variables
    int SR_age;

    printf("\n\n");

    printf("Enter Age: ");
    scanf("%d", &SR_age);

    if (SR_age >= 18)
    {
        printf("Yu are eligible for voting\n");
    }

    return 0;
}