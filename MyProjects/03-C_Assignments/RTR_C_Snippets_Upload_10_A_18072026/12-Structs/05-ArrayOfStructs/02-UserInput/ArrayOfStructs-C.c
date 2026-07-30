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

    int i;

    for (i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("\n\n");
        printf("Please enter data for employee number %d\n", (i + 1));

        printf("Please enter name:\n");
        MyGetString(employeeRecords[i].SR_name, SR_NAME_LENGTH);

        printf("Please enter employee age\n");
        scanf("%d", &employeeRecords[i].SR_age);

        printf("\n\n");
        printf("Please enter employees sex (M/m for Male and F/f for Female)\n");
        scanf(" %c", &employeeRecords[i].SR_sex);
        printf("%c", employeeRecords[i].SR_sex);
        employeeRecords[i]
            .SR_sex = toupper(employeeRecords[i].SR_sex);

        printf("\n\n");
        printf("Please enter employees salary\n");
        scanf("%f", &employeeRecords[i].SR_salary);

        printf("\n\n");
        printf("Is employee married? Y/y or N/n \n");
        scanf(" %c", &employeeRecords[i].SR_maritalStatus);
        printf("%c", employeeRecords[i].SR_maritalStatus);
        employeeRecords[i].SR_maritalStatus = toupper(employeeRecords[i].SR_maritalStatus);

        printf("\n\n");
    }

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

        printf("Marital Status: \t %c\n\n", employeeRecords[i].SR_maritalStatus);
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void MyGetString(char str[], int str_size)
{
    int i = 0;
    char ch;

    while ((ch = getchar()) == '\n')
    {
    }
    do
    {
        str[i++] = ch;
        ch = getchar();
    } while (ch != '\n' && i < str_size - 1);

    str[i] = '\0';
}