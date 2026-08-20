#include <stdio.h>

int main()
{
    // function declaration
    void Addition(int a, int b);

    // variable declaration
    int num1 = 500,
        num2 = 200;
    int c = 0;

    // logic
    Addition(num1, num2);

    // print the addition
    // printf("Addition is %d \n", c);

        return (0);
}

void Addition(int yenaraPahileVariable, int yenaraDusravariable)
{
    // c = a + b;
    int miKeleliBerij = 0;

    miKeleliBerij = yenaraPahileVariable + yenaraDusravariable;

    // return (miKeleliBerij);

    printf("Addition is %d \n", miKeleliBerij);
}
