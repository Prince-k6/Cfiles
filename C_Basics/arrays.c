//create an array of marks of size 3
// #include<stdio.h>
// int main(){
//     int marks[3];
//     printf("enter phy:");
//     scanf("%d",&marks[0]);
//     printf("enter chem:");
//     scanf("%d",&marks[1]);
//     printf("enter maths:");
//     scanf("%d",&marks[2]);
//     printf("phy=%d,chem=%d,maths=%d\n",marks[0],marks[1],marks[2]);

//     return 0;
// }


//WAP to enter price of 3 items & print their final cost including gst
// #include<stdio.h>
// float percent_of(float a,float b);   // a% of b
// float percent_of(float a,float b){
//     return (a*b)/100;
// }
// int main(){
//     float price[3];
//     printf("price of item1:");
//     scanf("%f",&price[0]);
//     printf("price of item2:");
//     scanf("%f",&price[1]);
//     printf("price of item3:");
//     scanf("%f",&price[2]);
//     //final cost = price + percent_of(18%)
//     printf("-------------------------------------------------\n");
//     printf("items     price        final price(including gst)\n");
//     printf("-------------------------------------------------\n");
//     for (int i=1;i<=3;i+=1){
//         float gst=percent_of(18,price[i-1]);
//         printf("item%d     %f       %f\n",i,price[i-1],price[i-1]+ gst);
//     }
//     return 0;
// }

//wap to enter 3 marks at a single time
// #include<stdio.h>
// int main(){
//     int marks[]={99,98,97};
//     for (int i=1;i<=3;i+=1){
//         printf("%d\n",marks[i-1]);
//     }
//     return 0;
// }


            

//array is a pointer: (*) value at address basically points at the first element of an array 
// i.e it stores the address of the first element for the address of whole array



                             //pointer arithmatic
// #include<stdio.h>
// int main(){
//     int age =22;
//     int *ptr=&age;
//     printf("ptr=%u\n",ptr);
//     ptr++;
//     printf("ptr++=%u\n",ptr);
//     ptr--;
//     printf("ptr--=%u\n\n",ptr);

//     float price=20.00;
//     float *ptr1=&price;
//     printf("ptr1=%u\n",ptr1);
//     ptr1++;
//     printf("ptr1++=%u\n",ptr1);
//     ptr1--;
//     printf("ptr1--=%u\n\n",ptr1);

//     char ch='#';
//     char *ptr2=&ch;
//     printf("ptr2=%u\n",ptr2);
//     ptr2++;
//     printf("ptr2++=%u\n",ptr2);
//     ptr2--;
//     printf("ptr2--=%u\n",ptr2);
//     return 0;
// }


               // travesing elements
// #include<stdio.h>
// int main(){
//     int aadhar[12]={9,7,7,7,8,2,7,8,3,0,5,8};
//     // for (int i=0;i<10;i++){
//     //     printf("enter index %d:",i);
//     //     scanf("%d",&aadhar[i]);
//     //}
    
//           //traversing(accessing) elements of an array
//     for (int i=0;i<12;i++){
//         // printf("index %d=%d",i,aadhar[i]);
//         printf("%d\t",aadhar[i]);    //  "\t" for tab space
//     }
//     printf("\n");
//     return 0;
// }



                   // array in function argument
// #include<stdio.h>
// void numbers(int arr[],int n); 
// //or void numbers(int *arr,int n);
// void numbers(int arr[],int n){
// //or void numbers(int *arr,int n){
//     for( int i=0;i<n;i++){
//         printf("%d\t",arr[i]);
//     }printf("\n");
// }
// int main(){
//     int arr[]={1,2,3,4,5,6};
//     numbers(arr,6);
//     return 0;
// }



                          //multidimensional array
// #include<stdio.h>
// int main(){
//     int arr[2][2]={{1,2},{3,4}};  //stored like matrix
//     printf("%d\n",arr[0][0]);
//     printf("%d\n",arr[0][1]);      // accessed like matrix
//     printf("%d\n",arr[1][1]);
//     return 0;
// }

// int main(){
//     int stu[2][3]; //={{90,98,89},{96,88,94}}
//     stu[0][0]=90;
//     stu[0][1]=98;
//     stu[0][2]=89;
//     stu[1][0]=96;
//     stu[1][1]=88;
//     stu[1][2]=94;
//     printf("stu[1][2]=%d\n",stu[1][2]);
// }

//WAF to count the number of odd numbers in an array
// #include<stdio.h>
// void count(int arr[],int n);
// void count(int arr[],int n){
//     int cnt_odd=0;
//     for (int i=0;i<n;i++){
//         if (arr[i]%2!=0){
//             cnt_odd+=1;
//         }else{
//             continue;
//         }
//     }printf("no.of odd numbers =%d\n",cnt_odd);
// }
// int main(){
//     int arr[]={11,2,99,563,43,456,6327};
//     count(arr,7);
//     return 0;
// }




//WAF to reverse an array
// #include<stdio.h>
// void reverse(int arr[],int n);
// void reverse(int arr[],int n){
//     for (int i=(n-1);i>=0;i--){
//         printf("%d\t",arr[i]);
//     }
// }
// int main(){
//     int arr[]={5,4,3,2,1};
//     reverse(arr,5);
//     return 0;
// }


#include<stdio.h>
//function to print an array
void print_arr(int arr[],int n);
void print_arr(int arr[],int n){
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
//fibonacci using arrays
void fibonacci(int n);
void fibonacci(int n){
    int fib[n];
    fib[0]=0;
    fib[1]=1;
    for (int i=2;i<n;i++){
        fib[i]=fib[i-1]+fib[i-2];  //important
    }
    print_arr(fib,n);
}
int main(){
    int n;
    printf("enter n:");
    scanf("%d",&n);
    fibonacci(n);
}



// create a 2D array for storing tables of 2 & 3
// #include<stdio.h>
// int main(){
//     int tables[2][10];
//     for (int i=0;i<10;i++){
//         tables[0][i]=2*(i+1);
//     }
//     for (int i=0;i<10;i++){
//         tables[1][i]=3*(i+1);
//     }
//     for (int j=0;j<=1;j++){
//         for (int i=0;i<10;i++){
//             printf("%d\t",tables[j][i]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//program to find sum of given elements in an array
// #include<stdio.h>
// int main(){
//     int arr[]={15,10,13,12};
//     int sum=0;
//     int a=sizeof(arr)/4;
//     for (int i=0;i<a;i++){
//         sum=sum+arr[i];
//     }
//     printf("sum=%d\n",sum);
//     return 0;
// }

//using recursion find the sum of elements in an array
// #include<stdio.h>
// int sum(int arr[],int n);
// int sum(int arr[],int n){
//     if (n==0){
//         return 0;
//     }else{
//         return arr[0]+ sum(arr+1,n-1);              //why arr+1??
//     }
// }
// int main(){
//     int arr[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int val=sum(arr,n);
//     printf("sum=%d\n",val);
//     return 0;
// }


//Given a 2D array of order M * N, the task is to find out the sum of elements of the matrix.
// #include<stdio.h>
// int main(){
//     int arr[2][2]={{1,2},{3,4}};
//     int sum=0;
//     for (int i=0;i<2;i++){
//         for (int j=0;j<2;j++){
//             sum+=arr[i][j];
//         }
//     }
//     printf("sum of elements=%d\n",sum);
//     printf("%lu\n",sizeof(arr));
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int arr[4][4]={{1,2,3,4},
//                    {5,6,7,8},
//                    {9,10,11,12},
//                    {13,14,15,16}};
//     int sum=0;
//     for (int i=0;i<4;i++){
//         for (int j=0;j<4;j++){
//             sum+=arr[i][j];
//         }
//     }
//     printf("sum of elements=%d\n",sum);
//     printf("%lu\n",sizeof(arr));
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int arr[10];
//     for(int i=0;i<10;i++){
//         printf("element %d:",i);
//         scanf("%d",&arr[i]);
//     }
//     for (int i=0;i<10;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

//reversing an array
// #include<stdio.h>
// int main(){
//     int n;
//     printf("enter the no. of elements to store:");
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++){
//         printf("element %d:",i);
//         scanf("%d",&arr[i]);
//     }
//     printf("in actual order :\n");
//     for (int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     printf("in reverse order:\n");
//     for(int i=n-1;i>=0;i--){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
// }




//finding no. of duplicate items
// #include<stdio.h>
// int main(){
//     int arr[]={1,1,1};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     printf("length of array=%d\n",n);
//     for (int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     int count=0;
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             if(arr[i]==arr[j]){
//                 count++;
//                 break;
//             }

//         }
//     }
//     printf("duplicate items=%d\n",count);
//     return 0;
// }


//printing unique elements
// #include<stdio.h>
// int main(){
//     int arr[]={3,2,2,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     printf("length of array=%d\n",n);
//     for (int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("\n");
//     int count;
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             count =0;
//             if(arr[i]==arr[j]){
//                 count=1;
//                 break;
//             }
//         }
//     if(count==0){
//         printf("%d ",arr[i]);
//     }
//     }
//     printf("\n");
//     return 0;
// }