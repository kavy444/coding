#include <stdio.h>

int main()
{
    int a;
    printf("enter a choice");
    scanf("%d", a);
    switch (a)
    {
    case 1:
        printf("sarthak is ladki");
        break;
    case 2:
        printf("sarthak is hijda");
        break;
    case 3:
        printf("sarthak is sarthaki");
        break;
    default:
        printf("sarthak is a fool");
    }
    return 0;
}