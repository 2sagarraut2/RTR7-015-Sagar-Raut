#include <stdio.h>
#include <string.h>

#define SR_NAME_LENGTH 100
#define SR_MARITAL_STATUS 10

typedef struct
{
    char SR_name[SR_NAME_LENGTH];
    int SR_age;
    float SR_salary;
    char SR_sex;
    char SR_maritalStatus[SR_MARITAL_STATUS];
} Employee;

int main(void)
{
    Employee employeeRecords[5];

    char employeeSagar[] = "Sagar";
    char employeeYogesh[] = "Yogesh";
    char employeeHemant[] = "Hemant";
    char employeePrasad[] = "Prasad";
    char employeePranali[] = "Pranali";

    int i;

    strcpy(employeeRecords[0].SR_name, employeeSagar);
    employeeRecords[0].SR_age = 30;
    employeeRecords[0].SR_sex = 'M';
    employeeRecords[0].SR_salary = 500000.0f;
    strcpy(employeeRecords[0].SR_maritalStatus, "Married");

    strcpy(employeeRecords[1].SR_name, employeeYogesh);
    employeeRecords[1].SR_age = 29;
    employeeRecords[1].SR_sex = 'M';
    employeeRecords[1].SR_salary = 600000.0f;
    strcpy(employeeRecords[1].SR_maritalStatus, "Unmarried");

    strcpy(employeeRecords[2].SR_name, employeeHemant);
    employeeRecords[2].SR_age = 32;
    employeeRecords[2].SR_sex = 'M';
    employeeRecords[2].SR_salary = 700000.0f;
    strcpy(employeeRecords[2].SR_maritalStatus, "Married");

    strcpy(employeeRecords[3].SR_name, employeePrasad);
    employeeRecords[3].SR_age = 27;
    employeeRecords[3].SR_sex = 'M';
    employeeRecords[3].SR_salary = 400000.0f;
    strcpy(employeeRecords[3].SR_maritalStatus, "Unmarried");

    strcpy(employeeRecords[4].SR_name, employeePranali);
    employeeRecords[4].SR_age = 31;
    employeeRecords[4].SR_sex = 'F';
    employeeRecords[4].SR_salary = 700000.0f;
    strcpy(employeeRecords[4].SR_maritalStatus, "Married");

    printf("\n\n");
    printf("**** Display employee records ****\n");

    for (i = 0; i < 5; i++)
    {
        printf("Employee Number %d \n", (i + 1));
        printf("Name: \t %s\n", employeeRecords[i].SR_name);
        printf("Age: \t %d\n", employeeRecords[i].SR_age);
        printf("Salary: \t %f\n", employeeRecords[i].SR_salary);

        if (employeeRecords[i].SR_sex == 'M' || employeeRecords[i].SR_sex == 'm')
        {
            printf("Sex: \t Male\n");
        }
        else
        {
            printf("Sex: \t Female\n");
        }

        printf("Marital Status: \t %s\n\n", employeeRecords[i].SR_maritalStatus);
    }

    printf("\n\n--End--\n\n");
    return (0);
}