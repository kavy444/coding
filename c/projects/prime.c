#include <stdio.h>
//program to print prime
int main()
{
    int n, prime = 0;
    printf("enter the no");
    scanf("%d", &n);
    for (int a = 2; a < n; a++)
    {
        if (n % a == 0 && n != 2)
        {
            prime = 1;
            break;
        }
    }
    if (prime )//just do not write prime=1 only write prime 
    {
        printf("no is not prime");
    }
    else
    {
        printf("no is prime");
    }
    return 0;
}