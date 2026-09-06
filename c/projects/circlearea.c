#include <stdio.h>

int main(){
    int radius,height;
    printf("enter radius");
    scanf("%d",&radius);
    printf("the area is %f\n",3.14*radius*radius);
    printf("enter the height if you want to make circle a cylinder");
    scanf("%d",&height);
    printf("the area of cylinder with same height is %f",3.14*radius*radius*height);
     return 0;
}