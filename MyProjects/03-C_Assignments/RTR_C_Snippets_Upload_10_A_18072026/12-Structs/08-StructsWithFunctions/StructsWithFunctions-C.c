#include <stdio.h>

struct MyData
{
    int SR_i;
    float SR_f;
    double SR_d;
    char SR_c;
};

int main(void)
{
    struct MyData AddStructMembers(struct MyData, struct MyData, struct MyData);

    struct MyData SR_data1, SR_data2, SR_data3, SR_answerData;

    printf("\n\n\n\n");
    printf("Enter integer value for 'i' of 'struct MyData SR_data1' ; ");
    scanf("%d", &SR_data1.SR_i);

    printf("\n\n");
    printf("Enter floating point value for 'f' of 'struct MyData SR_data1' ; ");
    scanf("%f", &SR_data1.SR_f);

    printf("\n\n");
    printf("Enter double value for 'f' of 'struct MyData SR_data1' ; ");
    scanf("%lf", &SR_data1.SR_d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData SR_data1' ; ");
    scanf(" %c", &SR_data1.SR_c);

    printf("\n\n\n\n");
    printf("Enter integer value for 'i' of 'struct MyData SR_data2' ; ");
    scanf("%d", &SR_data2.SR_i);

    printf("\n\n");
    printf("Enter floating point value for 'f' of 'struct MyData SR_data2' ; ");
    scanf("%f", &SR_data2.SR_f);

    printf("\n\n");
    printf("Enter double value for 'd' of 'struct MyData SR_data2' ; ");
    scanf("%lf", &SR_data2.SR_d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData SR_data2' ; ");
    scanf(" %c", &SR_data2.SR_c);

    printf("\n\n\n\n");
    printf("Enter integer value for 'i' of 'struct MyData SR_data3' ; ");
    scanf("%d", &SR_data3.SR_i);

    printf("\n\n");
    printf("Enter floating point value for 'f' of 'struct MyData SR_data3' ; ");
    scanf("%f", &SR_data3.SR_f);

    printf("\n\n");
    printf("Enter double value for 'd' of 'struct MyData SR_data3' ; ");
    scanf("%lf", &SR_data3.SR_d);

    printf("\n\n");
    printf("Enter character value for 'c' of 'struct MyData SR_data3' ; ");
    scanf(" %c", &SR_data3.SR_c);

    SR_answerData = AddStructMembers(SR_data1, SR_data2, SR_data3);

    printf("\n\n\n\n");
    printf("*** Answer ***\n");
    printf("SR_answerData.i = %d\n", SR_answerData.SR_i);
    printf("SR_answerData.f = %f\n", SR_answerData.SR_f);
    printf("SR_answerData.d = %lf\n", SR_answerData.SR_d);

    SR_answerData.SR_c = SR_data1.SR_c;
    printf("SR_answerData.c (from SR_data1) %c\n\n", SR_answerData.SR_c);

    SR_answerData.SR_c = SR_data2.SR_c;
    printf("SR_answerData.c (from SR_data2) %c\n\n", SR_answerData.SR_c);

    SR_answerData.SR_c = SR_data3.SR_c;
    printf("SR_answerData.c (from SR_data3) %c\n\n", SR_answerData.SR_c);

    return (0);
}

struct MyData AddStructMembers(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
    struct MyData answer;

    answer.SR_i = md_one.SR_i + md_two.SR_i + md_three.SR_i;
    answer.SR_f = md_one.SR_f + md_two.SR_f + md_three.SR_f;
    answer.SR_d = md_one.SR_d + md_two.SR_d + md_three.SR_d;

    return (answer);
};
