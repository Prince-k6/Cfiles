#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void merge(int arr[],int st,int mid,int end){
    int i=st,j=mid+1,k=0,temp[end-st+1];

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
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
    
    for(i=st,k=0;i<=end;i++,k++){
        arr[i]=temp[k];
    }
}

void mergeSort(int arr[],int st,int end){
    if(st<end){
        int mid = st + (end-st)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}

// int main(){
//     int arr[] = {2,3,4,5,3,5,8,9};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     mergeSort(arr,0,n-1);

//     for(int i=0;i<n;i++){
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

int main(){
    int n;
    clock_t start,end;
    double time_taken;

    printf("Enter the no. of elements to be sorted : ");
    scanf("%d",&n);
    int arr[n];

    printf("Generating %d random Elements...\n",n);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i] = rand() % 10000 ;   //random numbers between 1 and 9999
    }

    printf("Sorting the array using merge Sort....\n");
    start = clock();
    mergeSort(arr,0,n-1);
    end = clock();

    // printf("\nSorted array : ");
    // for(int i=0;i<n;i++){
    //     printf("%d\t",arr[i]);
    // }
    // printf("\n");

    time_taken = ((double) (end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken to sort %d Elements using mergeSort : %lf \n",n,time_taken);
    return 0;
}
