#include <stdio.h>

int main()
{
    float a, b, c, d,avg,rounded;
    printf("enter the marks in 1st subject");
    scanf("%f",&a);
    printf("enter the marks in 2nd subject");
    scanf("%f",&b );
    printf("enter the marks in 3rd subject");
    scanf("%f",&c);
    printf("enter the marks in 4th subject");
    scanf("%f",&d );
    avg=(a+b+c+d)/4;
    printf("the average marks of student is %f",avg);
    return 0;
}
/*
input a=20
      b=30
      c=40
      d=50
output=70*/