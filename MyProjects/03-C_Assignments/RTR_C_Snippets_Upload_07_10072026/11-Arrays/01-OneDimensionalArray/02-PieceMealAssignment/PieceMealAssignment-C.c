#include <stdio.h>

int main(void)
{
    int iArrayOne[10];
    int iArrayTwo[10];

    iArrayOne[0] = 3;
    iArrayOne[1] = 6;
    iArrayOne[2] = 9;
    iArrayOne[3] = 12;
    iArrayOne[4] = 15;
    iArrayOne[5] = 18;
    iArrayOne[6] = 21;
    iArrayOne[7] = 24;
    iArrayOne[8] = 27;
    iArrayOne[9] = 30;

    printf("\n\n");
    printf("Piece-meal (hard coded) assignment and display of elments of Array 'iArrayOne[]:\n");
    printf("1st element of Array 'iArrayOne[]' or element at 0th index of Array 'iArrayOne[] = %d\n", iArrayOne[0]);
    printf("2nd element of Array 'iArrayOne[]' or element at 1st index of Array 'iArrayOne[] = %d\n", iArrayOne[1]);
    printf("3rd element of Array 'iArrayOne[]' or element at 2nd index of Array 'iArrayOne[] = %d\n", iArrayOne[2]);
    printf("4th element of Array 'iArrayOne[]' or element at 3rd index of Array 'iArrayOne[] = %d\n", iArrayOne[3]);
    printf("5th element of Array 'iArrayOne[]' or element at 4th index of Array 'iArrayOne[] = %d\n", iArrayOne[4]);
    printf("6th element of Array 'iArrayOne[]' or element at 5th index of Array 'iArrayOne[] = %d\n", iArrayOne[5]);
    printf("7th element of Array 'iArrayOne[]' or element at 6th index of Array 'iArrayOne[] = %d\n", iArrayOne[6]);
    printf("8th element of Array 'iArrayOne[]' or element at 7th index of Array 'iArrayOne[] = %d\n", iArrayOne[7]);
    printf("9th element of Array 'iArrayOne[]' or element at 8th index of Array 'iArrayOne[] = %d\n", iArrayOne[8]);
    printf("10th element of Array 'iArrayOne[]' or element at 9th index of Array 'iArrayOne[] = %d\n", iArrayOne[9]);

    printf("\n\n");
    printf("Enter first element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[0]);
    printf("Enter second element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[1]);
    printf("Enter third element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[2]);
    printf("Enter fourth element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[3]);
    printf("Enter fifth element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[4]);
    printf("Enter sixth element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[5]);
    printf("Enter seventh element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[6]);
    printf("Enter eighth element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[7]);
    printf("Enter ninth element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[8]);
    printf("Enter tength element of array iArrayTwo[]:");
    scanf("%d", &iArrayTwo[9]);

    printf("\n\n");
    printf("piece-meal (User input) assignment and display of elements of Array iArrayTwo[]:\n\n");
    printf("1st element of iArrayTwo[] or element at 0th index of array iArrayTwo = %d\n", iArrayTwo[0]);
    printf("2nd element of iArrayTwo[] or element at 2nd index of array iArrayTwo = %d\n", iArrayTwo[1]);
    printf("3rd element of iArrayTwo[] or element at 3rd index of array iArrayTwo = %d\n", iArrayTwo[2]);
    printf("4th element of iArrayTwo[] or element at 4th index of array iArrayTwo = %d\n", iArrayTwo[3]);
    printf("5th element of iArrayTwo[] or element at 5th index of array iArrayTwo = %d\n", iArrayTwo[4]);
    printf("6th element of iArrayTwo[] or element at 6th index of array iArrayTwo = %d\n", iArrayTwo[5]);
    printf("7th element of iArrayTwo[] or element at 7th index of array iArrayTwo = %d\n", iArrayTwo[6]);
    printf("8th element of iArrayTwo[] or element at 8th index of array iArrayTwo = %d\n", iArrayTwo[7]);
    printf("9th element of iArrayTwo[] or element at 9th index of array iArrayTwo = %d\n", iArrayTwo[8]);
    printf("10th element of iArrayTwo[] or element at 10th index of array iArrayTwo = %d\n", iArrayTwo[9]);

    printf("\n\n--End--\n\n");
    return (0);
}