#include <stdio.h>

int main()
{
    int a = 3, b = 8;
    int c = a + b;
    printf("%d\n", c);

    printf("%d\n", a / b);
    // a/b will print  0 due to type demotion
    return 0;
}
