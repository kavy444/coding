#include <stdio.h>

int main()
{
    printf("enter a\n");
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("i am good");
        break;
    case 2:
        printf("i am bad");
    default:
        printf("jhki");
    }
    return 0;
}