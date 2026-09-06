#include <stdio.h>

int main(){
    int a,b,c,d;
    printf("enter a 3 digit no ");
    scanf("%d",&a);
    b=a/100;
    c=(a%100)/10;
    d=(a%100)%10;
    printf("the first digit is %d\nthe second digit is %d\nthe third digit is %d\n",b,c,d);
    printf("the sum of the digit is %d",(b+c+d));
     return 0;
}
/*sample input=123
  sample output=6*/