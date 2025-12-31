#include<stdio.h>

int main(){
    int m,n;
    printf("enter size of array 1:");
    scanf("%d",&m);
    printf("enter size of array 2:");
    scanf("%d",&n);
    int arr1[m],arr2[n];
    printf("enter array 1 elements\n");
    for(int i=0;i<m;i++){
        scanf("%d",&arr1[i]);
    }
    printf("enter array 2 elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    int arr3[m+n];
    printf("merged array\n");
    for(int i=0,j=0;i<m+n;i++){
        if(i<m){
            arr3[i]=arr1[i];
        }
        else if(i>=m){
            arr3[i]=arr2[j];
            j++;
        }
        printf("%d\t",arr3[i]);
    }
    printf("\n");
    return 0;
}