//Design and implement C/C++ Program to find a subset of a given set S = {sl, s2,..,sn} of
//n positive integers whose sum is equal to a given positive integer d.

#include<stdio.h>

int n;
void findSubsets(int i,int d, int arr[],int subset[],int size){
    if(d==0){
        printf("{ ");
        for(int i=0;i<size-1;i++){
            printf("%d,",subset[i]);
        }
        printf("%d }\n",subset[size-1]);
        return;
    }
    if(d<0 || i>=n){
        return;
    }
    subset[size] = arr[i];
    findSubsets(i+1,d-arr[i],arr,subset,size+1);
    findSubsets(i+1,d,arr,subset, size);
}
int main(){
    // int arr[] = {1,2,5,6,8};
    // int arr[] = {3,10,11,20};
    int arr[] = {1,2,3,4};
    // int arr[] = {2,7,10};

    n = sizeof(arr)/sizeof(arr[0]);
    // int d = 9;
    // int d = 24;
    // int d =10;
    int d =7;

    int subset[n];

    findSubsets(0,d,arr,subset,0); 
    printf("No other subset found\n");
    return 0;
}

