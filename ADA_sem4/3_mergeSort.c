#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge_sort(int[], int, int);
void merge(int[], int, int, int);

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n];

    printf("Generating %d random elements...\n", n);

    srand(time(NULL)); // Seed for random number generator

    for(i = 0; i < n; i++){
        arr[i] = rand() % 10000; // Generate random integers between 0 and 9999
    }

    printf("Sorting the array using Merge Sort...\n");

    start = clock(); // Start timer

    merge_sort(arr, 0, n - 1);

    end = clock(); // Stop timer

    printf("Sorted array: \n");

    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to sort %d elements: %lf seconds", n, time_taken);

    return 0;
}

void merge_sort(int arr[], int low, int high)
{
    int mid;

    if(low < high){
        mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, temp[high - low + 1];

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= high){
        temp[k++] = arr[j++];
    }

    for(i = low, k = 0; i <= high; i++, k++){
        arr[i] = temp[k];
    }
}
