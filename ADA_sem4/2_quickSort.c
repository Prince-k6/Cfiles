// 2.Write C/C++ programs to sort a given set of n integer elements 
//using Quick Sort method and compute its time Complexity. Run the 
//program for varied values of n> 5000 and record the time taken to sort.
// Plot a graph of the time taken versus non graph sheet. The elements 
//can be read from a file or can be generated using the random number 
//generator. Demonstrate using C/C++ how the divide-and-conquer method 
//works along with its time complexity analysis: worst case, average 
//case and best case.



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);

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

    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000; // Generate random integers between 0 and 9999
    }

    printf("Sorting the array using Quick Sort...\n");

    start = clock(); // Start timer

    quick_sort(arr, 0, n - 1);

    end = clock(); // Stop timer

    printf("Sorted array: \n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to sort %d elements: %lf seconds", n, time_taken);

    return 0;
}

void quick_sort(int arr[], int low, int high)
{
    int pivot_index;

    if(low < high)
    {
        pivot_index = partition(arr, low, high);

        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, j, temp;

    for(j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;

            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high]
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
