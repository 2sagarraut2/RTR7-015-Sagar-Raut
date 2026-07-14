#include <stdio.h>

int main()
{

    int SR_age;

    printf("\n\n");

    printf("Enter SR_age: ");
    scanf("%d", &SR_age);

    printf("\n\n");

    if (SR_age >= 18)
    {
        printf("Entering if-block...\n\n");
        printf("You are eligible for voting !!! \n\n");
    }
    else
    {
        printf("Entering else-block...\n\n");
        printf("You not are eligible for voting bad luck !!! \n\n");
    }

    printf("Bye\n\n");

    return 0;
}