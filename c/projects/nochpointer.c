#include <stdio.h>
int change(int*);
int change(int* i){
    *i=*i * 10;
    return *i;
    
};
int main(){
    int i;
    printf("enter the no you want to change");
    scanf("%d",&i);
    printf("the new value of i is %d",change(&i));
    printf("\n the new value in place of i is %d",i);
     return 0;
}