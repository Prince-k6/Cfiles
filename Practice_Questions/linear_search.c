//linear search using functions-> return -1 if element not present else return the index of the element
#include<stdio.h>
 
int ls(int n,int arr[],int target){     //function declaration and defination
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n,tgt;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter target:");
    scanf("%d",&tgt);
    
    int index=ls(n,arr,tgt);  //function call
    if (index!=-1){
        printf("Element %d found at index %d\n",tgt,index);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}