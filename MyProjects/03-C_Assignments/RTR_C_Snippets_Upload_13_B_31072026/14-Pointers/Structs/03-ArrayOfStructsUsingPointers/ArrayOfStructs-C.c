#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LENGTH 100
#define MARITAL_STAUS 10

typedef struct
{
    char SR_name[NAME_LENGTH];
    unsigned int SR_age;
    char SR_sex;
    float SR_salary;
    char SR_maritalStatus;
} SR_Employee;

int main(void)
{
    void SR_MyGetString(char[], int);

    SR_Employee *pEMployeeRecord = NULL;
    int SR_numEmployees = 0, i = 0;

    printf("\n\n");
    printf("Enter number of EMployees whose details you want to record\n");
    scanf("%d", &SR_numEmployees);

    printf("\n\n");
    pEMployeeRecord = (SR_Employee *)malloc(sizeof(SR_Employee) * SR_numEmployees);

    if (pEMployeeRecord == NULL)
    {
        printf("Failed to allocate the memory for %d employees\n", SR_numEmployees);
    }
    else
    {
        printf("Memory allocated success for %d employees\n\n", SR_numEmployees);
    }

    for (i = 0; i < SR_numEmployees; i++)
    {
        printf("Please enter data for Employees\n");
        printf("Enter Employee name\n");
        SR_MyGetString(pEMployeeRecord[i].SR_name, NAME_LENGTH);

        printf("\n\n");
        printf("Please enter employee age\n");
        scanf("%u", &pEMployeeRecord[i].SR_age);

        printf("\n\n");
        printf("Please enter sex of employee (M/m for male & F/f for female)\n");
        scanf(" %c", &pEMployeeRecord[i].SR_sex);
        pEMployeeRecord[i].SR_sex = toupper(pEMployeeRecord[i].SR_sex);

        printf("\n\n");
        printf("Please enter marital status of employee (Enter 'Y' if married else enter 'N')\n");
        scanf("%c", &pEMployeeRecord[i].SR_maritalStatus);
        pEMployeeRecord[i].SR_maritalStatus = toupper(pEMployeeRecord[i].SR_maritalStatus);

        printf("\n\n");
        printf("Please enter salary of the employee\n");
        scanf("%f", &pEMployeeRecord[i].SR_salary);
    }

    printf("Details entered by you are as follows\n\n");
    for (i = 0; i < SR_numEmployees; i++)
    {
        printf("SR_Employee Name: \t %s\n", pEMployeeRecord[i].SR_name);
        printf("SR_Employee Sex: \t %c\n", pEMployeeRecord[i].SR_sex);
        printf("SR_Employee Age: \t %u\n", pEMployeeRecord[i].SR_age);
        printf("SR_Employee Salary: \t %f\n", pEMployeeRecord[i].SR_salary);

        printf("SR_Employee marital status: \t");
        if (pEMployeeRecord[i].SR_maritalStatus == 'Y')
        {
            printf("Married");
        }
        else
        {
            printf("Unmarried\n\n");
        }
    }

    if (pEMployeeRecord)
    {
        free(pEMployeeRecord);
        pEMployeeRecord = NULL;
        printf("Memory allocated tp %d employees has been released", SR_numEmployees);
    }
}

void SR_MyGetString(char str[], int str_size)
{
    int SR_i = 0;
    char ch;

    while ((ch = getchar()) == '\n')
    {
    }
    do
    {
        str[SR_i++] = ch;
        ch = getchar();
    } while (ch != '\n' && SR_i < str_size - 1);

    str[SR_i] = '\0';
}