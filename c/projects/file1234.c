#include <stdio.h>

int main(){
    FILE * fp;
    fp=fopen("kavy.txt","r+");
    char arr[100];
    char arr1[100];
    char a;
    int c;
   
       while((a=fgetc(fp))!=EOF){
        if(a>='a'&&a<='z'){
            c=ftell(fp);
            fseek(fp,-1,SEEK_CUR);
            a=a-32;
            fputc(a,fp);
            
        }}
    
    rewind(fp);
    fgets(arr1,sizeof(arr1),fp);
    puts(arr1);

     return 0;
}