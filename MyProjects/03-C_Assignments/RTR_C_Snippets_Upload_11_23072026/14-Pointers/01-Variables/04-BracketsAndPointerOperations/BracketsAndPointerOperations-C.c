#include <stdio.h>

int main(void)
{
    int SR_num;
    int *ptr = NULL;
    int ans = 0;

    SR_num = 5;
    ptr = &SR_num;

    printf("\n\n");
    printf("SR_num = %d\n", SR_num);
    printf("&SR_num = %p\n", &SR_num);
    printf("*(&SR_num) = %d\n", *(&SR_num));
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);

    printf("\n\n");

    printf("Answer of (ptr + 10) = %p\n", (ptr + 10));

    printf("Answer of *(ptr + 10) = %d\n", *(ptr + 10));

    printf("Answer of (*ptr + 10) = %d\n", (*ptr + 10));

    ++*ptr;

    printf("Answer of ++*ptr : %d\n", *ptr);

    *ptr++;
    printf("Answer of *ptr++ : %d\n", *ptr);

    ptr = &SR_num;

    (*ptr)++;

    printf("Asnwer of (*ptr)++ : %d\n\n", *ptr);

    printf("\n\n--End--\n\n");
    return (0);
}