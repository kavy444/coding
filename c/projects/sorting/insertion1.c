#include <stdio.h>

int main(){
    int n,temp,i,j;
    printf("enter no of elements you want to print");
    scanf("%d",&n);
    int a[n];
    printf("enter the elements");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        int curr=a[i];
        int prev=i-1;
        while(prev>=0&&a[prev]>curr){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
     return 0;
}