#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptrSR_iArray = NULL;

    unsigned int SR_intArrayLength = 0;
    int SR_i = 0;

    printf("\n\n");
    printf("Enter the number of elements you want in integer array \n");
    scanf("%d", &SR_intArrayLength);

    ptrSR_iArray = (int *)malloc(sizeof(int) * SR_intArrayLength);
    if (ptrSR_iArray == NULL)
    {
        printf("\n\n");
        printf("Memory aloocation for integer array has failed! exiting now!!\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocated for integer array\n");
        printf("Memory address from %p to %p have been allocated for integer array!!\n\n", ptrSR_iArray, (ptrSR_iArray + (SR_intArrayLength - 1)));
    }

    printf("\n\n");
    printf("Enter %d elements for integer array\n\n", SR_intArrayLength);

    for (SR_i = 0; SR_i < SR_intArrayLength; SR_i++)
    {
        scanf("%d", (ptrSR_iArray + SR_i));
    }

    printf("\n\n");
    printf("The integer array entered by you, consist of %d elements\n", SR_intArrayLength);

    for (SR_i = 0; SR_i < SR_intArrayLength; SR_i++)
    {
        printf("ptrSR_iArray[%d] = %d \t \t  at address  &ptrSR_iArray[%d] : %p\n", SR_i, ptrSR_iArray[SR_i], SR_i, &ptrSR_iArray[SR_i]);
    }

    printf("\n\n");
    for (SR_i = 0; SR_i < SR_intArrayLength; SR_i++)
    {
        printf("ptrSR_iArray[%d] = %d \t \t  at address  &ptrSR_iArray[%d] : %p\n", SR_i, *(ptrSR_iArray + SR_i), SR_i, (ptrSR_iArray + SR_i));
    }

    if (ptrSR_iArray)
    {
        free(ptrSR_iArray);
        ptrSR_iArray = NULL;

        printf("\n\n");
        printf("Memory allocated for integer array has been successfully freed!");
    }

    printf("\n\n--End--\n\n");
    return (0);
}