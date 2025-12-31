//1
// #include<stdio.h>

// int main(){
//     int age=22;
//     int *ptr=&age;             //*--> value at addresss, &-->address of
    
//     printf("%p\n",&age);         //%p is used to printing the memory address of a variable
//     printf("%d\n",*ptr);
//     printf("%d\n",*(&age));

//     return 0;
// }



//2
// int main(){
//     // float  price=100.00;
//     // float *ptr=&price;
//     // float **pptr=&ptr;
//     // printf("%f\n",**pptr);
//     // printf("%f\n",*ptr);

//     int i=5;
//     int *ptr=&i;
//     int **pptr=&ptr;              //pptr--> pointer to pointer
//     printf("*ptr=%d\n",*ptr);
//     printf("**pptr=%d\n",**pptr); //getting the value using pointer to pointer

//     return 0;

// }



/*3
void square(int n);
void _square(int *n);


int main(){
    int number = 4;
    square(number);
    printf("number=%d\n",number);

    _square(&number);
    printf("number=%d\n",number);
    return 0;
}
void square(int n){
    n=n*n;
    printf("square=%d\n",n);
}
void _square(int *n){
    (*n)=(*n)*(*n);
    printf("square=%d\n",*n);
} 
*/



//4.WAP to show the basic declaration of a pointer.
/*Here is m=10, n and o are two integer variable and *z is an integer*/
// #include<stdio.h>
// int main(){
//     int m=10,n,o;
//     int *z=&m;
//     printf("z stores the address of m=%p\n",z);  // this will print the address of m
//     printf("*z stores the value of m=%d\n",*z);  // this will print the value at that address
//     printf("&m is the address of m=%p\n",&m);       //&m stores the memory address
//     printf("&n stores the address of n=%p\n",&n);
//     printf("&o stores the address of o=%p\n",&o);
//     printf("&z stores the address of o=%p\n",&z);
//     return 0;
// }


//5.Write a program in C to demonstrate the use of the &(address of) and *(value at address) operators.
// #include<stdio.h>
// int main(){
//     int m=300;
//     int *ptr1=&m;

//     float fx=300.60006;
//     float *ptr2=&fx;

//     char cht='z';
//     char *ptr3=&cht;

//     printf("m=%d\nfx=%f\ncht=%c\n",m,fx,cht);
//     printf("using & operator\n");
//     printf("-----------------\n");
//     printf("address of m = %p\n",&m);
//     printf("address of fx = %p\n",&fx);
//     printf("address of cht = %p\n",&cht);


//     printf("\nusing & and * operator\n");
//     printf("------------------------\n");
//     printf("value at address of m=%d\n",*ptr1);
//     printf("value at address of fx=%f\n",*ptr2);
//     printf("value at address of cht=%c\n",*ptr3);

//     return 0;
// }




//6.Write a program in C to add two numbers using pointers.
// #include<stdio.h>
// int main(){
//     int a=5;
//     int b=7;
//     int *ptr1=&a;
//     int *ptr2=&b;
//     printf("sum=%d\n",(*ptr1)+(*ptr2));
//     return 0;

// }


//7.waf to find max of 2 numbers using pointers
// #include<stdio.h>

// int main(){
//     int a=5;
//     int b=11;
//     int *ptr1=&a;
//     int *ptr2=&b;
//     if ((*ptr1)>(*ptr2)){
//         printf("%d>%d\n",*ptr1,*ptr2);
//     }else{
//         printf("%d>%d\n",*ptr2,*ptr1);
//     }    return 0;
// }

// #include<stdio.h>
// void reverse(int a,int b);
// void reverse(int a,int b){
//     int a=10;
//     int b=20;
//     int sum=a+b;
// }
 
//swapping 2 numbers using call by reference
// void Reverse(int *ptr1,int *ptr2);
// void Reverse(int *ptr1,int *ptr2){
//     *ptr1=10;
//     *ptr2=20;
// }

// int main(){
//     int a=20;
//     int b=10;
//     printf("a=%d,b=%d\n",a,b);
//     Reverse(&a,&b);       // call by reference
//     printf("a=%d,b=%d\n",a,b);
//     return 0;
// }


//swap using pointers
// #include<stdio.h>
// void swap(int *n1,int *n2){
//     int temp=*n1;
//     *n1=*n2;
//     *n2=temp;
// }

// int main(){
//     int a,b;
//     a=5;b=6;
//     printf("before swaping\n");
//     printf("a->%d\tb->%d\n",a,b);
//     printf("after swapping\n");
//     swap(&a,&b);
//     printf("a->%d\tb->%d\n",a,b);
//     return 0;
// }

#include<stdio.h>
int main(){
    int nb;
    int *ptr;
    nb=42;
    ptr=&nb;
    printf("%d %0.60f\n",*ptr,*(float*)ptr);
    return 0;
}