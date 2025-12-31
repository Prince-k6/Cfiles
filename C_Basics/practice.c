                                                //find the output of code...
//1.
// #include<stdio.h>
// int main(){
//     int a=50000;
//     int b=4;
//     float c=3;
//     printf("%.4d\n",a);      //a=50000
//     printf("%.5d\n",b);      //b=00004
//     printf("%.3f\n",c);      //c=3.000
//     return 0; 
// }

// 2.
// #include<stdio.h>
// int main(){
//     int i = 10,*ptr;
//     ptr= &i;
//     void *vptr; 
//     vptr = &ptr;
//     printf("\nValue of iptr = %d\n",i);
//     printf("\nValue of iptr = %d\n",*ptr);
//     printf("\nValue of iptr = %d\n",**(int**)vptr);
//     return 0;
// 

//3.
// #include<stdio.h>
// int main(){
//    int a, b, c;
//    char *p = 0;
//    int *q = 0;
//    double *r = 0;
//    a = (int)(p);
//    b = (int)(q+1);
//    c = (int)(r);
//    printf("%d %d  %d",a, b, c);
//    return 0;
// }

//4.
// #include<stdio.h>
// float square(float a){
//     float val=a*a;
//     return val;
// }
// int main(){
//     float a;
//     printf("enter number:");
//     scanf("%f",&a);
//     printf("square=%.2f\n",square(a));
//     return 0;
//}

// #include<stdio.h>
// int main(){
//     int a=1,b=1,c;
//     c=a++ +b;
//     printf("%d,%d,%d\n",a,b,c);
//     int i=1;
//     printf("%d,%d\n",i,i++);
//     return 0;
// }

//reading aeray elements and computing odd_sum and even_sum
// #include<stdio.h>
// int main(){
//     int n,odd_sum=0,even_sum=0,sum=0;
//     printf("enter n:");
//     scanf("%d",&n);
//     int arr[n];
//     printf("enter array elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//         sum+=arr[i];
//         if(arr[i]%2==0){
//             even_sum+=arr[i];
//         }
//         else{
//             odd_sum+=arr[i];
//         }
//     }
//     printf("odd sum=%d\neven sum=%d\naverage=%f\n",odd_sum,even_sum,sum/(float) n);
//     return 0;
// }


int ls(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
}

int bs(int arr[],int n,int key){
    int high=n;
    int low=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

#include<stdio.h>
int main(){
    int n,key;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements in sorted order\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the key element to be searched:");
    scanf("%d",&key);

    //using linear search
    int idx1=ls(arr,n,key);
    if (idx1 !=-1) printf("element found at index %d\n",idx1);
    else printf("element not found\n");

    //using binary search
    int idx2=ls(arr,n,key);
    if (idx2 !=-1) printf("element found at index %d\n",idx2);
    else printf("element not found\n");
    return 0;
}