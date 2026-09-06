#include <stdio.h>
#include <string.h>//in steructure used can add different data types
struct employee{
    int code;
    float salary;
    char name[10];
};//semicolon is necessary
int main(){
    struct employee j1,e2;
    strcpy(j1.name,"kavyansh");
    j1.salary=67.98;
    printf("%f,%s\n",j1.salary,j1.name);
    strcpy(e2.name,"jatin");
    e2.salary=90.89;
    printf("%f,%s",e2.salary,e2.name);

    return 0;
} 