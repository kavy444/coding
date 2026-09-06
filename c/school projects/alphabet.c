#include <stdio.h>

int main(){
    int a;
    printf("enter no of times you want to run the loop");
    scanf("%d",&a);
    for(int i=1;i<=a;i++){
        char b='A';
        for(int j=1;j<=i;j++){
            printf("%c ",b);
            b=b+1;
        }
        printf("\n");
    }
     return 0;
}