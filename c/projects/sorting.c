#include <stdio.h>

int main(){
    int a[]={12,2,34,17},n=4;
    int j, i,min,temp;
 /*   for(i=0;i<4;i++){
        min=i;
        for(j=i+1;j<4;j++){
            
            if(a[min]>a[j]){
                temp=a[j];
                a[j]=a[min];
                a[min]=temp;
            }
        }
    }*/
    /*for(i=1;i<n;i++){
        min=a[i];
        j=i;
        if(min<a[j-1]){
            while(a[j]<a[j-1] && j>0){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
                j--;
            }
        }
        
    }*/
   for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
        if(a[j]>a[j+1]){
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
        }
    }
   }
    for(i=0;i<4;i++){
        printf("%d ",a[i]);
    }
    int k=2,b=0,low=0,high=n-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(k<a[mid]){
            high=mid-1;

        }
        else if(k==a[mid]){
            b=1;
            break;
        }
        else if(k>a[mid]){
            low=mid+1;
        }
    }
    if(b==1){
        printf("no found");

    }

     return 0;
     
}