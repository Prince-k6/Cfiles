#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int st,int end){
    int idx = st-1;
    int pivot = arr[end];

    for(int j=st;j<end;j++){
        if(arr[j] <= pivot){
            idx++;
            swap(&arr[idx],&arr[j]);
        }
    }
    idx++;
    swap(&arr[idx], &arr[end]);
    return idx;
}

void quickSort(int arr[],int st,int end){
    if(st<end){
        int pvt_idx = partition(arr,st,end);
        quickSort(arr,st,pvt_idx-1);
        quickSort(arr,pvt_idx+1,end);
    }
}


int main(){
    int n;
    clock_t start, end;
    double time_taken;

    printf("enter n : ");
    scanf("%d",&n);

    int arr[n];
    printf("generating %d elements...\n",n);
    srand(time(NULL));
    for(int i =0;i<n;i++){
        arr[i] = rand()%10000;
    }

    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");

    printf("sorting the elements...\n");
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();

    printf("sorted array: \n");
    for(int i=0; i<n; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");

    time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("time taken to sort %d elements using mergeSort : %lf\n",n,time_taken);
    return 0;
}