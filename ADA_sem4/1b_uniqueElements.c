// Design and implement C program to determine whether all elements in a given array are unique 
// (i.e., no duplicate elements are present) also analyze the time complexity of the algorithm.
// Run the program for varied values of n> 5000 and record the time taken. Plot a graph of the time taken versus n.


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>



//function to check if all the elements in the array are unique
bool areElementsUnique(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int arr1[] = {34,33,64,14,64,75};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    if(areElementsUnique(arr1,n1)){
        printf("Array 1 : all elements are unique\n");
    }else{
        printf("Array 1 : all elements are not unique\n");
    }

    int arr2[] = {7,5,5,3,6,23,4,67,4,26,43};
    int n2 = sizeof(arr1)/sizeof(arr1[0]);
    if(areElementsUnique(arr2,n2)){
        printf("\nArray 2 : all elements are unique\n");
    }else{
        printf("\nArray 2 : all elements are not unique\n");
    }
    return 0;
}

// int main(){
//     int n;
//     clock_t start,end;
//     double time_taken;

//     printf("Enter the no.of Elements : ");
//     scanf("%d",&n);
//     int arr[n];

//     printf("Generating %d random Elements\n",n);
//     srand(time(NULL));   //random elements seed
//     for(int i=0;i<n;i++){
//         arr[i] = rand() % 10000;
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");

//     start = clock();
//     bool result = areElementsUnique(arr,n);
//     end = clock();

//     time_taken = ((double) (end-start))/CLOCKS_PER_SEC;
//     printf("\nAre all %d elements unique : %d ",n,result);
//     printf("\nTime taken to check if all elements are unique : %lf\n",time_taken);

//     return 0;
// }