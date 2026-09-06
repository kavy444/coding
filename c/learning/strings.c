#include <stdio.h>
#include<string.h>

int main(){
    //a string can be created just like array in 
    /*two ways
    first char bcc[]={'a','c',''c','c','/0'}
     the zero at the ending indicates the ending of array*/
     char bcc[]="kavyansh";
     for(int i=0;i<8;i++){
        printf("the string at %d is %c\n",i,bcc[i]);
     }
     printf("%s",bcc);
   //   printf("\n");
     char abc[33];
   //   scanf("%s",abc);
     //no & sign required with %s 
     //printf("%s",abc);
     fgets(abc,sizeof(abc),stdin);
     //gets all the character in same line
     puts(abc);
     //puts the cursor automatically in new line no need of \n
   //   printf("%s\n",abc);
     printf("%d",strlen(abc));
     return 0;
}