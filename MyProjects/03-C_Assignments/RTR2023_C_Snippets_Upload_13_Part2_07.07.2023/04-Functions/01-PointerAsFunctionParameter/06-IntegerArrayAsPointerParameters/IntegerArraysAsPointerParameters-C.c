#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void MultipleArrayElementsByNumber(int *, int, int);

    int *iArray = NULL;
    int numElements = 0;
    int i = 0, num = 0;

    printf("\n\n");
    printf("How many elements you want to add in Integer array\n");
    scanf("%d", &numElements);

    iArray = (int *)malloc(numElements * sizeof(int));

    if (iArray == NULL)
    {
        printf("Memory allocation to iArray has failed! exiting now!\n");
        exit(0);
    }

    printf("\n\n");
    printf("Enter %d elements for array\n", numElements);
    for (i = 0; i < numElements; i++)
    {
        scanf("%d", &iArray[i]);
    }

    printf("Array before passing to function MultipleArrayElementsByNumber(): \n\n");
    for (i = 0; i < numElements; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }

    printf("\n\n");
    printf("Enter a number by which you want to multiply every array element\n");
    scanf("%d", &num);

    MultipleArrayElementsByNumber(iArray, numElements, num);

    printf("\n\n");
    printf("Array returned by MultipleArrayElementsByNumber() function \n\n");

    for (i = 0; i < numElements; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }

    if (iArray)
    {
        free(iArray);
        iArray = NULL;
        printf("Memory allocated to iArray has been released\n\n");
    }

    printf("\n\n--End--\n\n");
    return (0);
}

void MultipleArrayElementsByNumber(int *arr, int iNumElements, int n)
{
    int i;

    for (i = 0; i < iNumElements; i++)
    {
        arr[i] = arr[i] * n;
    }
}