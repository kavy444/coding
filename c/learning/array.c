#include <stdio.h>

int main(){
    int marks[]={23,23,34,45,56};
    int* ptr=&marks[0];
    //above can also be written as int* ptr=marks;
    for(int i=0;i<6;i++){
        printf("the marks at position %d of marks array is %d\n",i,*ptr);
        ptr++;
    }
     return 0;
}