#include <stdio.h>

int main(void)
{

    // variables
    int a, b, p, q;
    char SR_ch_result_01, SR_ch_result_02;
    int SR_i_result_01, SR_i_result_02;

    printf("\n\n");

    a = 7;
    b = 5;
    SR_ch_result_01 = (a > b) ? 'A' : 'B';
    SR_i_result_01 = (a > b) ? a : b;
    printf("Ternary operator answer 1 ---- %c and %d. \n\n", SR_ch_result_01, SR_i_result_01);

    p = 30;
    q = 30;
    SR_ch_result_02 = (p != q) ? 'P' : 'Q';
    SR_i_result_02 = (p != q) ? p : q;
    printf("Ternary operator answer 2 --- %c and %d\n\n", SR_ch_result_02, SR_i_result_02);

    printf("\n\n");

    return 0;
}