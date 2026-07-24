#include <stdio.h>

int main(void)
{
    int SR_num;
    int *ptr = NULL;
    int *copyPtr = NULL;

    SR_num = 5;
    ptr = &SR_num;

    printf("\n\n");
    printf("*** Before copying ***\n\n");
    printf("SR_num = %d\n", SR_num);
    printf("&SR_num = %p\n", &SR_num);
    printf("*(&SR_num) = %d\n", *(&SR_num));
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);

    copyPtr = ptr;

    printf("\n\n");
    printf("*** After copying ***\n\n");
    printf("SR_num = %d\n", SR_num);
    printf("&SR_num = %p\n", &SR_num);
    printf("*(&SR_num) = %d\n", *(&SR_num));
    printf("ptr = %p\n", ptr);
    printf("*ptr = %d\n", *ptr);

    printf("\n\n--End--\n\n");
    return (0);
}