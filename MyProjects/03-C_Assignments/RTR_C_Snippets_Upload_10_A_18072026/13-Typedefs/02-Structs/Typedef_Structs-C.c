#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
    char SR_name[MAX_NAME_LENGTH];
    unsigned int SR_age;
    char SR_gender;
    double SR_salary;
};

struct MyData
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_c;
};

int main(void)
{

    typedef struct Employee MY_EMPLOYEE_TYPE;
    typedef struct MyData MY_DATA_TYPE;

    struct Employee emp = {"Funny", 25, 'M', 2000000.0};
    MY_EMPLOYEE_TYPE emp_typedef = {"Bunny", 23, 'F', 450000.0};

    struct MyData md = {56, 55.66f, 77.56, 'S'};
    MY_DATA_TYPE md_typedef;

    md_typedef.SR_i = 8;
    md_typedef.SR_f = 4.5f;
    md_typedef.SR_d = 9.03445;
    md_typedef.SR_c = 'G';

    printf("\n\n");
    printf("struct Employee: \n\n");
    printf("emp.SR_name            = %s\n", emp.SR_name);
    printf("emp.SR_age             = %d\n", emp.SR_age);
    printf("emp.SR_gender          = %c\n", emp.SR_gender);
    printf("emp.SR_salary          = %lf\n", emp.SR_salary);

    printf("\n\n");
    printf("MY_EMPLOYEE_TYPE : \n\n");
    printf("emp_typedef.SR_name        = %s\n", emp_typedef.SR_name);
    printf("emp_typedef.SR_age         = %d\n", emp_typedef.SR_age);
    printf("emp_typedef.SR_gender      = %c\n", emp_typedef.SR_gender);
    printf("emp_typedef.SR_salary      = %lf\n", emp_typedef.SR_salary);

    printf("\n\n");
    printf("Struct MyData : \n\n");
    printf("md.SR_i    = %i\n", md.SR_i);
    printf("md.SR_f    = %f\n", md.SR_f);
    printf("md.SR_d    = %lf\n", md.SR_d);
    printf("md.SR_c    = %c\n", md.SR_c);

    printf("\n\n");
    printf("Struct MyData : \n\n");
    printf("md_typedef.SR_i    = %i\n", md_typedef.SR_i);
    printf("md_typedef.SR_f    = %f\n", md_typedef.SR_f);
    printf("md_typedef.SR_d    = %lf\n", md_typedef.SR_d);
    printf("md_typedef.SR_c    = %c\n", md_typedef.SR_c);

    printf("\n\n--End--\n\n");
    return (0);
}