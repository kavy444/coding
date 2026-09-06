#include <stdio.h>

int main(){
   FILE *kavy;
     /*kavy=fopen("abc.txt","r");
     int a;
    fscanf(kavy,"%d",&a);
    printf("%d",a);*/
   /*kavy=fopen("abc.txt","w");
    int a=69;
    fprintf(kavy,"%d",a);
    fclose(kavy);*/
    /*kavy=fopen("abc.txt","a");
    int a=90;
    fprintf(kavy,"%d\t",a);*/
   /* kavy=fopen("abc.txt","r");
    char a = fgetc(kavy);
    printf("%c",a);
    fputc('b',kavy);*/
   /* kavy=fopen("abc.txt","r");
    char ch;
    while(1){
        ch=fgetc(kavy);
        printf("%c\n",ch);
        if(ch==EOF){
            break;
        }
    }*/
    fclose(kavy);
     return 0;
}