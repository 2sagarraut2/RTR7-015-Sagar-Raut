#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    int CalculateVariadic(int, ...);

    int answer = 0;

    printf("\n\n");

    answer = CalculateVariadic(5, 2, 4, 6, 8, 10);
    printf("Answer = %d\n", answer);

    answer = CalculateVariadic(10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3);
    printf("Answer = %d\n", answer);

    printf("\n\n--End--\n\n");
    return (0);
}

int CalculateVariadic(int a, ...)
{
    int sum = 0;
    int n;

    va_list numbersList;

    va_start(numbersList, a);

    while (a)
    {
        n = va_arg(numbersList, int);
        sum = sum + n;
        a--;
    }

    va_end(numbersList);

    return (sum);
}