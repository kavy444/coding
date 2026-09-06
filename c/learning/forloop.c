#include <stdio.h>

int main(){
    int n;
    printf("enter the last no till which you want to print");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
       
        if(i==10){
            break;//completely breaks the loop
        }
        if(i==5){
            continue;//skips that particular iteration
        }
         printf("the no are  %d \n",i);
    }
     return 0;
}