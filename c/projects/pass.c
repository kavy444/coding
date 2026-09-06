#include <stdio.h>

int main()
{
    float a, b, c, d;
    printf("enter the total marks in each subject from which marks are evaluated");
    scanf("%f", &d);
    printf("enter the marks in first subject");
    scanf("%f", &a);
    printf("enter the marks in second subject");
    scanf("%f", &b);
    printf("enter the marks in third subject");
    scanf("%f", &c);
    if ((a / d) * 100 >= 33 && (b / d) * 100 >= 33 && (c / d) * 100 >= 33 && (a + b + c) / d * 100 >= 40)
    {
        printf("student is pass");
    }
    else
    {
        printf("student is fail");
    }
    return 0;
}