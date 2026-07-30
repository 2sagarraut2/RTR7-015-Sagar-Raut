#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int SR_i;

    printf("Hello World!\n");
    printf("Number of command line arguments = %d\n\n", argc);

    printf("Command line arguments passed to this program are:\n");

    for (int SR_i = 0; SR_i < argc; SR_i++)
    {
        printf("Command line argument number %d = %s\n", (SR_i + 1), argv[SR_i]);
    }

    printf("First 20 environment variables passed to this program are: \n\n");
    for (int SR_i = 0; SR_i < 20; SR_i++)
    {
        printf("Environmental variable number %d = %s\n", (SR_i + 1), envp[SR_i]);
    }

    return 0;
}