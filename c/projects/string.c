#include <stdio.h>
#include <string.h>
int len(char a[]){
     int i=0,s;
     char c=a[i];
     while(c!='\0'){
          c=a[i];
          i++;

     }
     s=i-1;
     return s;



}
int main(){
     char str[]="kavyansh";
     int a,B;
     a=len(str); 
     B=strlen(str);
     printf("%d%d",a,B);
    
     return 0;
}