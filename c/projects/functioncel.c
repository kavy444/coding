#include <stdio.h>
int fahrenheit(a);
int fahrenheit(a){
    return (a-32)*5/9;

}
int main(){
    int b=77;
    printf("the temp in celcius is %d",fahrenheit(b));
     return 0;
}