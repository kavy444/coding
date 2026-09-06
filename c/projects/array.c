#include <stdio.h>

int main(){
    char a[5];
    int i;
    for(i=0;i<5;i++){
        scanf("%s",&a[i]);
    }
    char max=a[0];
    for(i=0;i<5;i++){

        if(a[i]>=max){
            max=a[i];
        }
    }
    printf("the max character in array is %c",max);

    
     return 0;
}