//to slice a string
#include <stdio.h>
#include <string.h>
int slice(char str[],int m,int n){
    char *ptr1=&str[m];
    //char *ptr2=&str[n];
    str=ptr1;
    str[n]='\0';
    return str;
}
int main(){
    char str[]="harry bhai";
    printf("%s",slice(str,2,8));
    return 0;
}