#include <stdio.h>

int main(){
     int a[20]={10,30,80,120},i;
     int *p=a;
     for(i=0;i<4;i++){
        *p=*p+8;
        p=p+1;
        *p=100;
        printf("%d",a[i]);
     }
     return 0;
}