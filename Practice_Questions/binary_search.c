
//program fo binary search

//return the index of an element from a sorted array else return -1
#include<stdio.h>

int bs(int n,int arr[],int tgt){
    int i,st,end,mid;
    st=0;
    end=n-1;
    for(i=st;i<end;i++){
        mid=(st+end)/2;
        if(tgt==arr[mid]){
            return mid;
        }else if(tgt>arr[mid]){
            st=mid+1;
        }else if(tgt<arr[mid]){
            end=mid-1;
        }
    }
    return -1;
}

int main(){
    int n=6;
    int arr[6]={23,25,27,32,33,37};
    int tgt;
    printf("enter target:");
    scanf("%d",&tgt);
    int index=bs(n,arr,tgt);
    if(index!=-1){
        printf("Element %d found at index %d\n",tgt,index);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
