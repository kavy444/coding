#include <stdio.h>

int main(){
    float a = 0.1;
    float *x=&a;  
    if ( *x == 0.1 )
        printf("IF");
    else if (*x == 0.1f)
        printf("ELSE IF");
    else
        printf("ELSE");

     return 0;
}