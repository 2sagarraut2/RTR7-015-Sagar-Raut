#include <stdio.h>

int main(void)
{

    int i_num, SR_num, i;

    printf("\n");

    printf("Enter an Integer value from which loop must start : \n");
    scanf("%d", &i_num);

    printf("How many digits do you want to print from %d ? : \n", i_num);
    scanf("%d", &SR_num);

    int i_num_new = i_num + SR_num;

    printf("Printing digits from %d to %d : \n\n", i_num, i_num_new);

    i = i_num;

    do
    {
        printf("\t%d\n", i);
        i++;
    } while (i <= i_num_new);

    printf("\n\n");
    return (0);
}