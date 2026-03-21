#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *arr,int lb,int ub);  // using first element as the pivot element
//     int pivot=arr[lb];
//     int st=lb;
//     int end=ub;
//     while(st<end){
//         while(st<ub && arr[st]<=pivot){
//             st++;
//         }
//         while(end>lb && arr[end]>=pivot){
//             end--;
//         }
//         if(st<end){
//             swap(&arr[st],&arr[end]);
//         }
//     }
//     swap(&arr[lb],&arr[end]);
//     return end;
// }

void quicksort(int *arr,int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}

int partition(int *arr,int st,int end){    //using last element as the pivot element
    int idx=st-1;
    int pivot=arr[end];

    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(&arr[j],&arr[idx]);
        }
    }
    idx++;
    swap(&arr[idx],&arr[end]);
    return idx;
}


int main(){
    int n;
    clock_t start,end;
    double time_taken;

    printf("enter the number of elements to be sorted:");
    scanf("%d",&n);
    int arr[n];

    // printf("generting %d random elements..\n",n);
    srand(time(NULL));   //seed for random values
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000; // for values to be in the range of 0-10000
    }

    // printf("sorting the array using quick sort\n");
    start=clock();
    quicksort(arr,0,n-1);
    end=clock();

    // for(int i=0;i<n;i++){
    //     printf("%d\t",arr[i]);
    // }printf("\n");

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements : %f seconds\n",n,time_taken);
    return 0;
}