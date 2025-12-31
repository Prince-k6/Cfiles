#include<stdio.h>

void add_element(int n,int arr[],int index,int element){
    if (index<n){
        for(int i=n-1;i>=index;i--){
            arr[i+1]=arr[i];
            arr[i]=element;
        }
    }else{
        arr[n]=element;
    }
    n++;
    printf("array after adding element\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    int arr[10];
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int index,element;
    printf("enter index of element and the element to be added\n");
    printf("index:");
    scanf("%d",&index);
    printf("Element:");
    scanf("%d",&element);
    add_element(n,arr,index,element);     //calling add_element function
    return 0;
}

                                //deleting an element from an array
// void delete_element(int n,int arr[],int index){
//     for(int i=index;i<n;i++){
//         arr[i]=arr[i+1];
//     }
//     n--;
//     printf("array after deleting element\n");
//     for(int i=0;i<n;i++){
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");
// }

// int main(){
//     int n;
//     int arr[10];
//     printf("enter the size of array:");
//     scanf("%d",&n);
//     printf("enter array elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     int index;
//     printf("enter index of element to be deleted:");
//     scanf("%d",&index);
//     delete_element(n,arr,index);         //calling delete_element function
// }