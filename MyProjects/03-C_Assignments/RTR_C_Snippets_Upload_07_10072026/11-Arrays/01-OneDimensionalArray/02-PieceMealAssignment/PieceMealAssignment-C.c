#include <stdio.h>

int main(void)
{
    int SR_iArrayOne[10];
    int SR_iArrayTwo[10];

    SR_iArrayOne[0] = 3;
    SR_iArrayOne[1] = 6;
    SR_iArrayOne[2] = 9;
    SR_iArrayOne[3] = 12;
    SR_iArrayOne[4] = 15;
    SR_iArrayOne[5] = 18;
    SR_iArrayOne[6] = 21;
    SR_iArrayOne[7] = 24;
    SR_iArrayOne[8] = 27;
    SR_iArrayOne[9] = 30;

    printf("\n\n");
    printf("Piece-meal (hard coded) assignment and display of elments of Array 'SR_iArrayOne[]:\n");
    printf("1st element of Array 'SR_iArrayOne[]' or element at 0th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[0]);
    printf("2nd element of Array 'SR_iArrayOne[]' or element at 1st index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[1]);
    printf("3rd element of Array 'SR_iArrayOne[]' or element at 2nd index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[2]);
    printf("4th element of Array 'SR_iArrayOne[]' or element at 3rd index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[3]);
    printf("5th element of Array 'SR_iArrayOne[]' or element at 4th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[4]);
    printf("6th element of Array 'SR_iArrayOne[]' or element at 5th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[5]);
    printf("7th element of Array 'SR_iArrayOne[]' or element at 6th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[6]);
    printf("8th element of Array 'SR_iArrayOne[]' or element at 7th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[7]);
    printf("9th element of Array 'SR_iArrayOne[]' or element at 8th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[8]);
    printf("10th element of Array 'SR_iArrayOne[]' or element at 9th index of Array 'SR_iArrayOne[] = %d\n", SR_iArrayOne[9]);

    printf("\n\n");
    printf("Enter first element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[0]);
    printf("Enter second element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[1]);
    printf("Enter third element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[2]);
    printf("Enter fourth element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[3]);
    printf("Enter fifth element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[4]);
    printf("Enter sixth element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[5]);
    printf("Enter seventh element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[6]);
    printf("Enter eighth element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[7]);
    printf("Enter ninth element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[8]);
    printf("Enter tength element of array SR_iArrayTwo[]:");
    scanf("%d", &SR_iArrayTwo[9]);

    printf("\n\n");
    printf("piece-meal (User input) assignment and display of elements of Array SR_iArrayTwo[]:\n\n");
    printf("1st element of SR_iArrayTwo[] or element at 0th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[0]);
    printf("2nd element of SR_iArrayTwo[] or element at 2nd index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[1]);
    printf("3rd element of SR_iArrayTwo[] or element at 3rd index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[2]);
    printf("4th element of SR_iArrayTwo[] or element at 4th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[3]);
    printf("5th element of SR_iArrayTwo[] or element at 5th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[4]);
    printf("6th element of SR_iArrayTwo[] or element at 6th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[5]);
    printf("7th element of SR_iArrayTwo[] or element at 7th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[6]);
    printf("8th element of SR_iArrayTwo[] or element at 8th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[7]);
    printf("9th element of SR_iArrayTwo[] or element at 9th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[8]);
    printf("10th element of SR_iArrayTwo[] or element at 10th index of array SR_iArrayTwo = %d\n", SR_iArrayTwo[9]);

    printf("\n\n--End--\n\n");
    return (0);
}