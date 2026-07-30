#include <stdio.h>
int main(void)
{
    // variable declarations
    int AM_num;
    int *AM_ptr = NULL;

    // code
    AM_num = 5;
    AM_ptr = &AM_num;
    printf("\n\n\t\t * *****Anoushka's Assignments ***** *\n\n");
    printf("\tnum= %d \n", AM_num);
    printf("\t&num =%p\n\n", &AM_num);
    printf("\t*(&AM_num) = % d\n\n ", *(&AM_num));
    printf("\n\t---- size of ptr (z)= %\n\n\n", sizeof(AM_ptr));

    printf("\tprt  = %p\n", AM_ptr);
    printf("Answer Of *(ptr+1)= %d\n\n", *(AM_ptr + 1));
    printf("Answer Of *(ptr+2)= %d\n\n", *(AM_ptr + 2));
    printf("Answer Of *(ptr+10)= %d\n\n", *(AM_ptr + 10));

    printf("Answer Of (*ptr+10)= %d\n\n", (*AM_ptr + 10));

    ++*AM_ptr;
    printf("Answer Of (++*ptr)= %d\n\n", *AM_ptr);

    *(AM_ptr)++;
    printf("Answer Of (*ptr++)= %d\n\n", *AM_ptr);

    AM_ptr = &AM_num;
    (*AM_ptr)++;
    printf("Answer Of (+ptr)++: %d\n\n", *AM_ptr);

    return (0);
}