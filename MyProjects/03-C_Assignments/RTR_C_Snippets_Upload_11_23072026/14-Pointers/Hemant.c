#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEMGTH 512

int main(void)
{
    char *SR_customStrlen(char *str);

    char hbArray_original[MAX_STRING_LEMGTH];

    // code
    // string input
    printf("\n");
    printf("Enter A string : \n");
    fgets(hbArray_original, MAX_STRING_LEMGTH, stdin);
    printf("\n");
    printf("The original string entered by you (i.e : 'hbArray_original[]' is : \n)");
    printf("%s\n", hbArray_original);

    // string output
    printf("\n");
    printf("The reversed string (i.e :'hbArray_Reverse[]' is : \n)");
    printf("%s\n", SR_customStrlen(hbArray_original));
    return (0);
}

char *SR_customStrlen(char *str)
{

    if (!str)
        return NULL;

    int i = 0;
    int j = strlen(str) - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}