#include <stdio.h>

typedef struct
{
    char SR_name[100];
    int SR_age;
    double SR_salary;
    char SR_sex;
    char SR_maritalStaus;

} Employee;

int main(void)
{
    printf("\n\n");
    printf("Sizes of data types and pointers to respective data are\n\n");

    printf("Sizeof(int) : %lu \t Size of pointer to int (int *) : %lu \t Size of pointer to pointer to int (int **) : %lu\n", sizeof(int), sizeof(int *), sizeof(int **));

    printf("Sizeof(float) : %lu \t Size of pointer to float (float *) : %lu \t Size of pointer to pointer to float (float **) : %lu\n", sizeof(float), sizeof(float *), sizeof(float **));

    printf("Sizeof(double) : %lu \t Size of pointer to double (double *) : %lu \t Size of pointer to pointer to double (double **) : %lu\n", sizeof(double), sizeof(double *), sizeof(double **));

    printf("Sizeof(char) : %lu \t Size of pointer to char (char *) : %lu \t Size of pointer to pointer to char (char **) : %lu\n", sizeof(char), sizeof(char *), sizeof(char **));

    printf("Sizeof(Employee) : %lu \t Size of pointer to Employee (Employee *) : %lu \t Size of pointer to pointer to Employee (Employee **) : %lu\n", sizeof(Employee), sizeof(Employee *), sizeof(Employee **));

    printf("\n\n--End--\n\n");
    return (0);
}