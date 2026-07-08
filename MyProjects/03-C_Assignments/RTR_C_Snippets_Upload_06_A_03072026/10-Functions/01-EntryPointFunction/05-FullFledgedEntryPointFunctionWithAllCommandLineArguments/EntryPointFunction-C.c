#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int i;

    printf("Hello World!\n");
    printf("Number of command line arguments = %d\n\n", argc);

    printf("Command line arguments passed to this program are:\n");

    for (int i = 0; i < argc; i++)
    {
        printf("Command line argument number %d = %s\n", (i + 1), argv[i]);
    }

    printf("First 20 environment variables passed to this program are: \n\n");
    for (int i = 0; i < 20; i++)
    {
        printf("Environmental variable number %d = %s\n", (i + 1), envp[i]);
    }

    return 0;
}