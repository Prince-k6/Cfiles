// 2.Write C/C++ programs to sort a given set of n integer elements using Quick Sort method and 
// compute its time Complexity. Run the program for varied values of n> 5000 and record the time taken 
// to sort. Plot a graph of the time taken versus non graph sheet. The elements can be read from a file 
// or can be generated using the random number generator. Demonstrate using C/C++ how the divide and
// conquer method works along with its time complexity analysis: worst case, average case and best case.



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a ,int *b){
    int temp = *b;
    *b=*a;
    *a=temp;
}

int partition(int arr[],int st,int end){
    int idx = st-1;
    int pivot = arr[end];

    for(int j=st;j<end;j++){      //last index is not included
        if(arr[j]<=pivot){
            idx++;
            swap(&arr[idx],&arr[j]);
        }
    }
    idx++;
    swap(&arr[idx],&arr[end]);
    return idx;
}

void quickSort(int arr[],int st,int end){
    if(st<end){
        int pivIdx = partition(arr,st,end);
        quickSort(arr,st,pivIdx-1);
        quickSort(arr,pivIdx+1,end);
    }
}

int main(){
    int n;
    clock_t start, end;
    double time_taken;

    printf("Enter the no. of elements to be sorted : ");
    scanf("%d",&n);
    int arr[n];

    printf("Generating %d random integers...\n",n);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        arr[i] =rand() % 10000 ;   //Generate random intgers between 0 to 9999
    }

    printf("sorting the array using Quick sort...\n");
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();

    printf("\nSorted array : ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    time_taken = ((double) (end-start))/CLOCKS_PER_SEC;
    printf("\nTime taken to sort %d elements : %lf \n",n,time_taken);
    return 0;
}



// int main(){
//     int n, i;
//     clock_t start, end;
//     double time_taken;
//     printf("Enter the number of elements to be sorted: ");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Generating %d random elements...\n", n);
//     srand(time(NULL)); // Seed for random number generator
//     for(i = 0; i < n; i++)
//     {
//         arr[i] = rand() % 10000; // Generate random integers between 0 and 9999
//     }
//     printf("Sorting the array using Quick Sort...\n");
//     start = clock(); // Start timer
//     quick_sort(arr, 0, n - 1);
//     end = clock(); // Stop timer
//     printf("Sorted array: \n");
//     for(i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
//     printf("\nTime taken to sort %d elements: %lf seconds", n, time_taken);
//     return 0;
// }
