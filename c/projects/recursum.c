#include <stdio.h>
 int sum(a);
 int sum(a){
    if(a==0||a==1){
        return 1;
    }
    return sum(a-1)+a;
 }
int main(){
    int c=5;
    printf("the sum of all numbers till 5 are %d",sum(c));
     return 0;
}