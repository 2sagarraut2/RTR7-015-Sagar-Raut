#include <stdio.h>

int main(void)
{
    int SR_num;
    int *SR_firstPointer = NULL;
    int **SR_secondPointer = NULL;

    SR_num = 10;

    printf("\n\n");
    printf(" ****** BEFORE SR_firstPointer = &SR_num ******\n\n");
    printf("Value of SR_num = %d\n\n", SR_num);
    printf("Address of SR_num = %p\n\n", &SR_num);
    printf("Value at address Of SR_num = %d\n\n", *(&SR_num));

    SR_firstPointer = &SR_num;

    printf("after SR_firstPointer = &SR_num\n\n");
    printf("Value of SR_num                = %d\n", SR_num);
    printf("Address of SR_num              = %p\n", &SR_num);
    printf("Value at address of SR_num     = %d\n", *SR_firstPointer);

    SR_secondPointer = &SR_firstPointer;

    printf("\n\n");
    printf("after SR_secondPointer = &SR_firstPointer\n\n");
    printf("Value of SR_num                    = %d\n", SR_num);
    printf("Address of SR_num                  = %p\n", &SR_num);
    printf("Value at address of SR_firstPointer *SR_secondPointer  = %p\n", *SR_secondPointer);
    printf("Value at address of SR_num (*SR_firstPointer) (*SR_secondPointer) = %d\n", **SR_secondPointer);

    printf("\n\n--End--\n\n");
    return (0);
}