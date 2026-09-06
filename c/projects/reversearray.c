#include <stdio.h>
void reverse(int arr[],int n){
    int temp;
    for(int i=0;i<(n/2);i++){
        temp=arr[i];
        arr[i]=arr[n-(i+1)];
        arr[n-(i+1)]=temp;
    }
}
int main()
{
    int c;
    printf("enter the length of the array");
    scanf("%d", &c);
    int arr[c];
    for (int a = 0; a < c; a++)
    {
        printf("the value at position %d", a);
        scanf("%d", &arr[a]);
    }
    for (int a = 0; a < c; a++)
    {
        printf(" %d ",  arr[a]);
    }
    printf("\n");
    reverse(arr,c);
    for (int a = 0; a < c; a++)
    {
        printf(" %d ",  arr[a]);
    }

    return 0;
}