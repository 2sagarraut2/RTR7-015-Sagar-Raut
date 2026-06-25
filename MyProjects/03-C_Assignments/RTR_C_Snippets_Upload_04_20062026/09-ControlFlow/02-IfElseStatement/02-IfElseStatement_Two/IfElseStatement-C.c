#include <stdio.h>

int main()
{

    int age;

    printf("\n\n");

    printf("Enter age: ");
    scanf("%d", &age);

    printf("\n\n");

    if (age >= 18)
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