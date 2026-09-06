#include <stdio.h>

int main(){
    //pointer stores the address of variable
    int i=78;
    int* j= &i;
    int** k=&j;//it will store the address of j
    printf("the address of %p\n",&i);
    printf("the address of i is %p\n",j);//both will print the samw address
    printf("the adress of j is %p\n",&j);
    printf("the value stored at j is %d or %d",*j,*(&i));
     return 0;
}//pointer can also be used in function cal to change the value of variable in main program
//ex int sum(int*,int*); taking address instead o f values
/*   int sum(int*a, int*b){
     *a= 6;
     return *a+*b 
     this program will change the value of a whether whatevere you might have written
     and will also give the sum of no 
     like this we can also use this in swapping numbers which will swap the values in the address}*/