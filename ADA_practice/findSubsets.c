#include<stdio.h>
#include<stdlib.h>

int n; 
void findSubsets(int i,int d,int arr[], int subset[], int size){     //for tracking subset
    if(d==0){
        //print the solution;
        printf("{ ");
        for(int i=0;i<size-1;i++){
            printf("%d,",subset[i]);
        }
        printf("%d }\n", subset[size-1]);
        return ;
    }
    if(d<0 || i>=n){
        return;
    }
    subset[size] = arr[i];
    findSubsets(i+1,d-arr[i], arr, subset,size+1);
    findSubsets(i+1,d,arr,subset,size);      //note here size is not incresed cause we are backtracking
}
int main(){

    int arr[] = {1,4,5,3,6,2,7};
    int d = 8;   //find the subsets wose sum is equal to d;

    n = sizeof(arr)/sizeof(arr[0]);
    int subset[n];

    findSubsets(0,d,arr,subset,0);

    return 0;
}