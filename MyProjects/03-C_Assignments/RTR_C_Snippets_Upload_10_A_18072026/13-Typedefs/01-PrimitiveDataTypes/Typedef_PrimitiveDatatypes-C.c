#include <stdio.h>

typedef int MY_INT;

int main(void)
{
    MY_INT Add(MY_INT, MY_INT);

    typedef int MY_INT;

    typedef float PVG_FLOAT;

    typedef char CHARACTER;

    typedef double MY_DOUBLE;

    typedef unsigned int UINT;
    typedef UINT HANDLE;
    typedef HANDLE HWND;
    typedef HANDLE HINSTANCE;

    MY_INT SR_a = 10, SR_i = 0;
    MY_INT SR_iArray[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};

    PVG_FLOAT SR_f_pvg = 50.1f;
    const PVG_FLOAT f_pvg_pi = 3.14f;

    CHARACTER ch = '*';
    CHARACTER SR_chArray01[] = "Hello";
    CHARACTER SR_chArray02[][10] = {"RTR", "BATCH", "2026-27"};

    MY_DOUBLE d = 5.6766;

    UINT uint = 4567;
    HANDLE handle = 3456;
    HWND hwnd = 8909;
    HINSTANCE hinstance = 45655;

    printf("\n\n");
    printf("Type MY_INT variable SR_a = %d\n", SR_a);

    printf("\n\n");
    for (SR_i = 0; SR_i < (sizeof(SR_iArray) / sizeof(int)); SR_i++)
    {
        printf("Type MY_INT array variable SR_iArray[%d] = %d\n", SR_i, SR_iArray[SR_i]);
    }
    printf("\n\n");

    printf("Type PVG_FLOAT variable f = %f\n\n", SR_f_pvg);
    printf("Type PVG_FLOAT constant f = %f\n\n", f_pvg_pi);

    printf("\n\n");
    printf("Type MY_DOUBLE variable d = %lf \n", d);

    printf("\n\n");
    printf("Type CHARACTER variable ch = %c \n", ch);

    printf("\n\n");
    printf("Type CHARACTER array variable SR_chArray01 = %s \n", SR_chArray01);

    printf("\n\n");
    for (SR_i = 0; SR_i < (sizeof(SR_chArray02) / sizeof(SR_chArray02[0])); SR_i++)
    {
        printf("%s \t", SR_chArray02[SR_i]);
    }
    printf("\n\n");

    printf("\n\n");
    printf("Type UINT variable uint = %u\n\n", uint);
    printf("Type HANDLE variable handle = %u\n\n", handle);
    printf("Type HWND variable hwnd = %u\n\n", hwnd);
    printf("Type HINSTANCE variable hinstance = %u\n\n", hinstance);

    MY_INT x = 90;
    MY_INT y = 30;
    MY_INT ret = 0;

    ret = Add(x, y);
    printf("ret = %d\n\n", ret);

    printf("\n\n--End--\n\n");
    return (0);
}

MY_INT Add(MY_INT SR_a, MY_INT b)
{
    MY_INT c = 0;
    c = SR_a + b;
    return (c);
}