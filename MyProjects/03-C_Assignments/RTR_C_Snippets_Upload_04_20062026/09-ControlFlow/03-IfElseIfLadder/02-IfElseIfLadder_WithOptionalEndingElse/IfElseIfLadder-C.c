#include <stdio.h>

int main()
{

    // variables
    int SR_num;

    printf("\n\n");

    printf("Enter value of SR_num: ");
    scanf("%d", &SR_num);

    if (SR_num < 0)
        printf("Num = %d is less than 0 !!!", SR_num);
    else if ((SR_num >= 0) && (SR_num <= 100))
        printf("Num %d is between 0 and 100", SR_num);

    else if ((SR_num > 100) && (SR_num <= 200))
        printf("Num %d is 100 between 200", SR_num);

    else if ((SR_num > 200) && (SR_num <= 300))
        printf("Num %d is between 200 and 300", SR_num);

    else if ((SR_num > 300) && (SR_num <= 400))
        printf("Num %d is between 300 and 400", SR_num);

    else if ((SR_num > 400) && (SR_num <= 500))
        printf("Num %d is between 400 and 500", SR_num);

    else if (SR_num > 500)
        printf("Num %d is greater than 500", SR_num);

    else
        printf("invalid input");

    return 0;
}