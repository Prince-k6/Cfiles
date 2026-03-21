#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int *arr,int n){     //uses 2 sub arryas and swaps the minimum value
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(i!=min){
            swap(&arr[i],&arr[min]);
        }
    }
}
int main(){
    int arr[]={1,2,5,7,8,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");

    return 0;
}