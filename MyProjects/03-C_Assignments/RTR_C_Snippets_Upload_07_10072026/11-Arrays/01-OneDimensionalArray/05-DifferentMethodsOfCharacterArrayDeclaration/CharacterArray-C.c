#include <stdio.h>

int main(void)
{
    char SR_chArray_01[] = {'A', 'S', 'T', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P'};

    char SR_chArray_02[9] = {'W', 'E', 'L', 'C', 'O', 'M', 'E', 'S'};

    char SR_chArray_03[] = {'Y', 'O', 'U', '\0'};

    char SR_chArray_04[] = "To";

    char SR_chArray_05[] = "REAL TIME RENDERING BATCH OF 2026-27";

    char SR_chArrayWithoutNULLTerminator[] = {'H', 'e', 'l', 'l', 'o'};

    printf("\n\n");

    printf("Size of SR_chArray_01 : %lu\n\n", sizeof(SR_chArray_01));
    printf("Size of SR_chArray_01 : %lu\n\n", sizeof(SR_chArray_02));
    printf("Size of SR_chArray_01 : %lu\n\n", sizeof(SR_chArray_03));
    printf("Size of SR_chArray_01 : %lu\n\n", sizeof(SR_chArray_04));
    printf("Size of SR_chArray_01 : %lu\n\n", sizeof(SR_chArray_05));

    printf("\n\n");

    printf("The Strings are : \n\n");
    printf("SR_chArray_01 : %s\n\n", SR_chArray_01);
    printf("SR_chArray_01 : %s\n\n", SR_chArray_02);
    printf("SR_chArray_01 : %s\n\n", SR_chArray_03);
    printf("SR_chArray_01 : %s\n\n", SR_chArray_04);
    printf("SR_chArray_01 : %s\n\n", SR_chArray_05);

    printf("\n\n");
    printf("size of SR_chArrayWithoutNULLTerminator : %lu\n\n", sizeof(SR_chArrayWithoutNULLTerminator));
    printf("SR_chArrayWithoutNULLTerminator : %s\n\n", SR_chArrayWithoutNULLTerminator);

    printf("\n\n--End--\n\n");
    return (0);
}