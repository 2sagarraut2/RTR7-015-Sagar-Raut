#include <stdio.h>

int main(void)
{

    int SR_AddIntegers(int, int);
    int SR_SubstractIntegers(int, int);
    float SR_AddFloats(float, float);

    typedef int (*AddIntegerFunctionPtr)(int, int);
    AddIntegerFunctionPtr SR_ptrToAddInt = NULL;
    AddIntegerFunctionPtr SR_ptrToSubInt = NULL;

    typedef float (*AddFloatsPtr)(float, float);
    AddFloatsPtr SR_ptrToAddFloat = NULL;

    int iAnswer = 0;
    float fAnswer = 0.0f;

    SR_ptrToAddInt = SR_AddIntegers;
    iAnswer = SR_ptrToAddInt(45, 5);
    printf("Sum of integers = %d\n", iAnswer);

    SR_ptrToSubInt = SR_SubstractIntegers;
    iAnswer = SR_ptrToSubInt(50, 10);
    printf("Substraction of integers = %d\n", iAnswer);

    SR_ptrToAddFloat = SR_AddFloats;
    fAnswer = SR_ptrToAddFloat(5.5, 4.5);
    printf("Sum of float = %f", fAnswer);

    printf("\n\n--End--\n\n");
    return (0);
}

int SR_AddIntegers(int a, int b)
{
    int c = 0;

    c = a + b;
    return (c);
}

int SR_SubstractIntegers(int a, int b)
{
    int c = 0;

    c = a - b;
    return (c);
}

float SR_AddFloats(float a, float b)
{
    float c = 0.0f;

    c = a + b;
    return (c);
}