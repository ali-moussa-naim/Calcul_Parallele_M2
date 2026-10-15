#include <stdio.h>

int main()
{
    int n = 64;
    int* p = &n;
    printf("%d", p[1]);

    return 0;
}