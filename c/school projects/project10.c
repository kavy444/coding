#include <stdio.h>
#include <math.h>
int main(){
    int x,y,d;
    printf("enter two no x and y ");
    scanf("%d%d",&x,&y);
    d=pow(x,y);
    printf("x raised to the power y is %d",d);
     return 0;
}
/*sample input=3,2
  sample output=9*/