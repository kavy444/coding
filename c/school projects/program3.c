#include <stdio.h>

int main(){
    float bp,da,hra,ta;
    printf("enter the basic pay ");
    scanf("%f",&bp);
    hra=0.1*bp;
    ta=0.05*bp;
    da=0.15*bp;
    printf("the hra is %f\n ",hra);
    printf("the ta is %f\n",ta);
    printf("the da is %f\n",da);
    printf("the gross is %f",(bp+da+hra+ta));
     return 0;
}
/*input =1000
  gross=1300
*/