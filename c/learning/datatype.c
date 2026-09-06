#include<stdio.h>
int main(){
    int a;
    printf("enter an integer");
    scanf("%d",&a);
    printf("enter a float");
    float b;
    scanf("%f",&b);
    char c;
    while (getchar() != '\n');
    printf("enter a char");
    scanf("%c",&c);
   
    printf("the integer is %d \n",a);
    printf("the FLOAT IS %f \n",b);
    printf("the char is %c \n",c);
    return 0;
}