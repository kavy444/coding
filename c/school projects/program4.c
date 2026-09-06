#include <stdio.h>

int main(){
    int s,h,m,sec;
    printf("enter the no of seconds");
    scanf("%d",&s);
    h=(s/3600);
    m=((s%3600)/60);
    sec=((s%3600)%60);
    printf("the conversion of sec is%dhrs%dmin%dsec",h,m,sec);
     return 0;
}
/*  input =3567
    output= 0hrs59min27sec*/
  
