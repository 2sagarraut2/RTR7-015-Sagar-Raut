#include <stdio.h>

int main(void)
{
    char SR_cArray[10];
    int SR_i;

    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        SR_cArray[SR_i] = (char)(SR_i + 70);
    }

    printf("\n\n");
    printf("Elements of character array\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_cArray[%d] = %c\n", SR_i, SR_cArray[SR_i]);
    }

    printf("\n\n");
    printf("Elements of character array with addresses\n\n");
    for (SR_i = 0; SR_i < 10; SR_i++)
    {
        printf("SR_cArray[%d] = %c \t \t address = %p\n", SR_i, SR_cArray[SR_i], &SR_cArray[SR_i]);
    }

    printf("\n\n--End--\n\n");
    return (0);
}