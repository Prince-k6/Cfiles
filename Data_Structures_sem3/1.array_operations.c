#include<stdio.h>

//traversal
void display(int arr[],int n){   
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
//insertion
int insert(int arr[],int *size, int element, int capacity, int index){
    if (*size>=capacity){
        return -1;
    }
    for(int i=*size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    (*size)++;
    return 1;
}
//deletion
void delete(int arr[],int *size,int index){//index->which element to delete
    for(int i=index;i<=*size-1;i++){
        arr[i]=arr[i+1];
    }
    (*size)--;
}
int main(){
    int arr[100]={1,2,3,4,5};
    int size=5;
    display(arr,size);

    //insertion
    int index=1;
    int element=25;
    insert(arr,&size,element,100,index);
    display(arr,size);

    //deletion
    delete(arr,&size,3);
    display(arr,size);

    return 0;                 
}
//binary search(searching operation)
int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, n, x);
    if(result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d",result);

}