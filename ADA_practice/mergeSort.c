#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int st,int mid,int end){
    int i=st,j=mid+1,k=0,temp[end-st+1];

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=end){
        temp[k++] = arr[j++];
    }

    for(int i=st,k=0;i<=end;i++,k++){
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[],int st,int end){
    if(st < end){
        int mid = st + (end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1, end);
        merge(arr,st,mid,end);
    }
}

int main(){
    int n;
    clock_t start, end;
    double time_taken;
    printf("enter n:");
    scanf("%d",&n);

    int arr[n];
    printf("generating %d elements\n",n);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i] = rand() % 10000 ;    //so that values stays in the range
    }

    // for(int i=0;i<n;i++){
    //     printf("%d  ",arr[i]);
    // }
    // printf("\n");

    printf("sorting array. . .\n");
    start = clock();
    mergeSort(arr,0,n-1);
    end = clock();

    // printf("sorted elements\n");
    // for(int i=0;i<n;i++){
    //     printf("%d  ",arr[i]);
    // }
    // printf("\n");

    time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements using merSort %lf\n", n, time_taken);

    return 0;
}