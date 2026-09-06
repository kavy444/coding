#include <stdio.h>
#include <string.h>
int main(){
     char st[]="kavyansh" ;
     //strcpy copies the source to the target 
     char target[60];
     strcpy(target,st);
     printf("%s %s\n",target, st) ; 
     //strcat is used to concatenate two strings
     char hup[]="loshali";
     strcat(st,hup);//in st the strings will concatenate
     printf("%s %s\n",st,hup);
    /*strcmp is used to compare two strings
    it returns 0 if two strings are same and positive if 
    first string written is greater ascii else negative*/
    int a=strcmp("far","joke"); 
    printf("%d\n",a);

     return 0;
}