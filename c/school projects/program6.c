#include <stdio.h>

int main(){
    float d,h;
    printf("enter the distance travelled by bike");
    scanf("%f",&d);
    printf("enter the time taken by the bike in hrs ");
    scanf("%f",&h);
    printf("the speed of bike is %f m/sec",((d*1000)/(h*3600)));
     return 0;
}
/*sample input=36
  sample output=10
*/