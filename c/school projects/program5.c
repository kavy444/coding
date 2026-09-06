#include <stdio.h>

int main(){
    float c;
    printf("enter the length in cm");
    scanf("%f",&c);
    printf("the length in metre is %f\n",(c/100));
    printf("the length in kilometre is %f\n",(c/100000));
     return 0;
}
/*input=10989
output= 109.890000m and 0.109890 km*/