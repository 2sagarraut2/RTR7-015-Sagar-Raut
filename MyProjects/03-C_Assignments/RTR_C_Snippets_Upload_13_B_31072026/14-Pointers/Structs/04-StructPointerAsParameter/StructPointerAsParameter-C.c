#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int SR_i;
    float SR_f;
    double SR_d;
} MyData;

int main(void)
{

    void SR_ChangeValues(MyData *);

    MyData *SR_pData = NULL;

    printf("\n\n");

    SR_pData = (MyData *)malloc(sizeof(MyData));

    if (SR_pData == NULL)
    {
        printf("Failed to allocate memory to struct MyData\n\n");
        exit(0);
    }
    else
    {
        printf("Memory successfuly allocated for struct MyData\n\n");
    }

    SR_pData->SR_i = 50;
    SR_pData->SR_f = 4.4f;
    SR_pData->SR_d = 6.6;

    printf("\n\n");
    printf("Data members of struct MyData are\n");
    printf("SR_i = %d\n", SR_pData->SR_i);
    printf("SR_f = %f\n", SR_pData->SR_f);
    printf("SR_d = %lf\n", SR_pData->SR_d);

    SR_ChangeValues(SR_pData);

    printf("\n\n");
    printf("Data members of struct MyData are\n");
    printf("SR_i = %d\n", SR_pData->SR_i);
    printf("SR_f = %f\n", SR_pData->SR_f);
    printf("SR_d = %lf\n", SR_pData->SR_d);

    if (SR_pData)
    {
        free(SR_pData);
        printf("Memory allocated for SR_pData has been releases!");
        SR_pData = NULL;
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void SR_ChangeValues(MyData *pParamData)
{
    pParamData->SR_i = 7;
    pParamData->SR_f = 1.1f;
    pParamData->SR_d = 5.5;
}