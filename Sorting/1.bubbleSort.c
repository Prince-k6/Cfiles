#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}
int main(){
    int arr[]={1,2,5,7,8,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");

    return 0;
}