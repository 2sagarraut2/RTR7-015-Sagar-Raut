#include <stdio.h>

typedef struct
{
    char myName[100];
    int myAge;          // 4 + 4 = 8
    float mySalary;     // 8
    char mysex;         // 8
    char maritalStatus; //
} Employee;

int main(void)
{

    Employee e;
    printf("\n\n");

    printf("Sizes of data types and pointers from struct data are:\n\n");

    printf("Size of (int) : %lu\t\t\t Size of pointer to int (int*) : %lu\n\n", sizeof(int), sizeof(int *));
    printf("Size of (float) : %lu\t\t\t Size of pointer to int (float*) : %lu\n\n", sizeof(float), sizeof(float *));
    printf("Size of (double) : %lu\t\t\t Size of pointer to int (double*) : %lu\n\n", sizeof(double), sizeof(double *));
    printf("Size of (char) : %lu\t\t\t Size of pointer to int (char*) : %lu\n\n", sizeof(char), sizeof(char *));
    printf("Size of (struct EMployee) : %lu\t\t\t Size of pointer to int (struct EMployee) : %lu\n\n", sizeof(Employee), sizeof(Employee *));

    printf("address of myName %p\n", &e.myName);
    printf("address of myAge %p\n", &e.myAge);
    printf("address of mySalary %p\n", &e.mySalary);
    printf("address of mysex %p\n", &e.mysex);
    printf("address of maritalStatus %p\n", &e.maritalStatus);

    printf("\n\n--End--\n\n");
    return (0);
}
