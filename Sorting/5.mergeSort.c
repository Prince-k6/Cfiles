#include<stdio.h>
#include<stdlib.h>
#include<time.h>



void merge(int *arr,int st,int mid,int end);


void merge_sort(int *arr,int low,int high){
    int mid;
    mid=(low+high)/2;
    if(low<high){
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge(int *arr,int low,int mid,int high){
    int i=low,j=mid+1,k=0,temp[high-low+1];

    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(i=low,k=0;i<=high;i++,k++){
        arr[i]=temp[k];
    }
}

int main(){
    clock_t start,end;
    double time_taken;
    int n;
    printf("enter the no. of elements to be sorted:");
    scanf("%d",&n);
    int arr[n];

    // printf("Gneratiing random elements...\n");
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000; // value will be in the range of 1 to 10000
    }

    // printf("sorting the array using merge sort\n");
    start=clock();
    merge_sort(arr,0,n-1);
    end=clock();

    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }printf("\n");
    
    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d element : %f seconds\n",n,time_taken);
    return 0;
}