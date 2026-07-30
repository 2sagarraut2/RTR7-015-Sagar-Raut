#include <stdio.h>
#include <ctype.h>

#define NUM_EMPLOYEES 5

#define SR_NAME_LENGTH 100
#define SR_MARITAL_STATUS 10

typedef struct
{
    char SR_name[SR_NAME_LENGTH];
    int SR_age;
    float SR_salary;
    char SR_sex;
    char SR_maritalStatus;
} Employee;

int main(void)
{
    void MyGetString(char[], int);

    Employee employeeRecords[NUM_EMPLOYEES];

    int SR_i;

    for (SR_i = 0; SR_i < NUM_EMPLOYEES; SR_i++)
    {
        printf("\n\n");
        printf("Please enter data for employee number %d\n", (SR_i + 1));

        printf("Please enter name:\n");
        MyGetString(employeeRecords[SR_i].SR_name, SR_NAME_LENGTH);

        printf("Please enter employee age\n");
        scanf("%d", &employeeRecords[SR_i].SR_age);

        printf("\n\n");
        printf("Please enter employees sex (M/m for Male and F/f for Female)\n");
        scanf(" %c", &employeeRecords[SR_i].SR_sex);
        printf("%c", employeeRecords[SR_i].SR_sex);
        employeeRecords[SR_i]
            .SR_sex = toupper(employeeRecords[SR_i].SR_sex);

        printf("\n\n");
        printf("Please enter employees salary\n");
        scanf("%f", &employeeRecords[SR_i].SR_salary);

        printf("\n\n");
        printf("Is employee married? Y/y or N/n \n");
        scanf(" %c", &employeeRecords[SR_i].SR_maritalStatus);
        printf("%c", employeeRecords[SR_i].SR_maritalStatus);
        employeeRecords[SR_i].SR_maritalStatus = toupper(employeeRecords[SR_i].SR_maritalStatus);

        printf("\n\n");
    }

    for (SR_i = 0; SR_i < 5; SR_i++)
    {
        printf("Employee Number %d \n", (SR_i + 1));
        printf("Name: \t %s\n", employeeRecords[SR_i].SR_name);
        printf("Age: \t %d\n", employeeRecords[SR_i].SR_age);
        printf("Salary: \t %f\n", employeeRecords[SR_i].SR_salary);

        if (employeeRecords[SR_i].SR_sex == 'M' || employeeRecords[SR_i].SR_sex == 'm')
        {
            printf("Sex: \t Male\n");
        }
        else
        {
            printf("Sex: \t Female\n");
        }

        printf("Marital Status: \t %c\n\n", employeeRecords[SR_i].SR_maritalStatus);
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void MyGetString(char str[], int str_size)
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