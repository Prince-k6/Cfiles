#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr,int n){
    int k=-1;   //find the max element
    for(int i=0;i<n;i++){
        if(arr[i]>k){
            k=arr[i];
        }
    }
    int freq[k];  //make a freq array that stores the freqeuncy of each element
    for(int i=0;i<=k;i++){
        freq[i]=0;
    }
    //find frequency
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //find cumulative frequency
    for(int i=1;i<n;i++){
        freq[i]+=freq[i-1];
    }
    //make answer array
    int ans[n];
    for(int i=n-1;i>=0;i--){
        ans[--freq[arr[i]]]=arr[i];
    }
    //store back to arr
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}
int main(){

    int arr[]={1,2,3,5,3,2,5,5,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    countSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");

    return 0;
}