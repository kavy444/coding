#include <stdio.h>

int main()
{
    int n, i = 10, s = 0;
    printf("enter the no in which you have to do the operation\n");
    scanf("%d", &n);
    for (n; i; i--)
    {
        printf("the reverse table is %d * %d=%d\n", n, i, n * i);
        s = s + (n * i);
    }

    printf("the sum of all multiples is =%d", s);
    int j=1,k=1;
    while(k<=n){
        j=j*k;
        k++;
    }
    printf("the factorial are %d",j);
    return 0;
}