#include <stdio.h>

int main(void)
{
    char SR_num;
    char* cptr = NULL;

    SR_num = 'A';

    printf("\n\n");

    printf("*** Before pointer assignment ***\n\n");

    printf("Value of num %c\n", SR_num);
    printf("Address of num %p\n", &SR_num);
    printf("Value at address of num %c\n", *(&SR_num));
    printf("Address of *cptr %p\n\n", &cptr);

    cptr = &SR_num;

    printf("*** After pointer assignment ***\n\n");
    printf("Value of num %c\n", *(&SR_num));
    printf("Address of num %p\n", cptr);
    printf("Value at address of num %c\n", *(cptr));
    printf("Address of *cptr %p\n\n", &cptr);

    printf("\n\n--End--\n\n");
    return (0);
}