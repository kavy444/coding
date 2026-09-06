#include <stdio.h>

int main(){
    char arr[100],temp;
    int i,c,count=0,a;
    printf("enter the string");
    fgets(arr,sizeof(arr),stdin);
    c=0;
    while(arr[c]!='\0'){
        a=c;
        i=a;
        while(arr[c]!=' '&& arr[c]!='\0'){
            count++;
            c++;
        }
        while(i<a+count/2){
            temp=arr[i];
            arr[i]=arr[count+a-1];
            arr[count+a-1]=temp;
            i++;
            
        }
        if(arr[c]==' '){
        c++;}
       count=0;
    }
    printf("the reversed string is ");
    puts(arr);
     return 0;
}