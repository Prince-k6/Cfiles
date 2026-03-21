#include<stdio.h>


void insertionSort(int *arr,int n){      //uses 2 sub arrays and stores the next element in temp variable and 
    for(int i=1;i<n;i++){             //inserts at the right place
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main(){
    int arr[]={1,2,5,7,8,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");

    return 0;
}
