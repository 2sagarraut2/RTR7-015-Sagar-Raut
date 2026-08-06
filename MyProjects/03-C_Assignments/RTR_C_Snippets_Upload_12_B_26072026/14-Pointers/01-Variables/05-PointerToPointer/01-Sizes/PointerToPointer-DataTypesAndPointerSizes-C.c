#include <stdio.h>

typedef struct
{
    char SR_name[100];    // 104
    int SR_age;           // 4
    float SR_salary;      // 4
    char SR_sex;          // 4
    char SR_maritalStaus; // 4
} Employee;

int main(void)
{
    // Employee e;

    printf("\n\n");
    printf("Sizes of data types and pointers to respective data are\n\n");

    printf("Sizeof(int) : %lu \t Size of pointer to int (int *) : %lu \t Size of pointer to pointer to int (int **) : %lu\n", sizeof(int), sizeof(int *), sizeof(int **));

    printf("Sizeof(float) : %lu \t Size of pointer to float (float *) : %lu \t Size of pointer to pointer to float (float **) : %lu\n", sizeof(float), sizeof(float *), sizeof(float **));

    printf("Sizeof(double) : %lu \t Size of pointer to double (double *) : %lu \t Size of pointer to pointer to double (double **) : %lu\n", sizeof(double), sizeof(double *), sizeof(double **));

    printf("Sizeof(char) : %lu \t Size of pointer to char (char *) : %lu \t Size of pointer to pointer to char (char **) : %lu\n", sizeof(char), sizeof(char *), sizeof(char **));

    printf("Sizeof(Employee) : %lu \t Size of pointer to Employee (Employee *) : %lu \t Size of pointer to pointer to Employee (Employee **) : %lu\n\n\n", sizeof(Employee), sizeof(Employee *), sizeof(Employee **));

    // printf("Address of SR_name is %p \n", &e.SR_name);
    // printf("Address of SR_age is %p \n", &e.SR_age);
    // printf("Address of SR_salary is %p \n", &e.SR_salary);
    // printf("Address of SR_sex is %p \n", &e.SR_sex);
    // printf("Address of SR_maritalStaus is %p \n", &e.SR_maritalStaus);

    printf("\n\n--End--\n\n");
    return (0);
}