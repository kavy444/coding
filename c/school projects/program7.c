#include <stdio.h>
#include <math.h>

int main(){
    float p,r,n,c,cp;
    printf("enter the principal amount");
    scanf("%f",&p);
    printf("enter the rate ");
    scanf("%f",&r);
    printf("enter the time ");
    scanf("%f",&n);
    c=(p*(pow((1+r/100),n)));
    cp=c-p;
    printf("the compound interest is %f",cp);
     return 0;
}
/*sample input=1000,1,1
  sample output=10*/