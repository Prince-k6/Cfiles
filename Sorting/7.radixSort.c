#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr,int n,int pos){
    int freq[10]={0};
    for(int i=0;i<n;i++){   //finding the frequency
        freq[(arr[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){   //finding cumulative frequency
        freq[i]+=freq[i-1];
    }

    int ans[n];
    for(int i=n-1;i>=0;i--){      //forming ans array
        ans[--freq[(arr[i]/pos)%10]]=arr[i];
    }
    for(int i=0;i<n;i++){      //storing back to ans array
        arr[i]=ans[i];
    }

}
void radixSort(int *arr,int n){
    int k=arr[0];
    for(int i=0;i<n;i++){    //find the max element
        if(arr[i]>k){
            k=arr[i];
        }
    }
    for(int pos=1;k/pos>0;pos*=10){
        countSort(arr,n,pos);
    }
}
int main(){
    int arr[]={345,23,9,876,56,498,120};
    int n=sizeof(arr)/sizeof(arr[0]);

    radixSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");

    return 0;
}