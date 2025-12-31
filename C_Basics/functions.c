#include<stdio.h>

// void hello();            //function prototype
// void hello(){            //function defination
//     prfloatf("hello person\n");
// }

// float main(){
//     hello();              //function call
//     bye();
//     return 0;
// }



// float sum (float a, float b);
// float sum(float a,float b){
//     return a+b;
// }

// float main(){
//     float a,b;
//     prfloatf("enter a:");
//     scanf("%d",&a);
//     prfloatf("enter b:");
//     scanf("%d",&b);
//     float s=sum(a,b);
//     prfloatf("sum=%d\n",s);
//     return 0;
// }


// void greeting( char country);
// void greeting(char country){
//     if (country=='i'| country=='I'){
//         prfloatf("namsate\n");
//     }else if(country=='f'|country=='F'){
//         prfloatf("bonjour\n");
//     }
// }
// float main(){
//     char country;
//     prfloatf("enter i for indian anf f for french:");
//     scanf("%c",&country);
//     greeting(country);
//     return 0;
// }

                                /* tables prfloating*/
// void tables(float n);
// void tables(float n){
//     for (float i=1;i<=10;i+=1){
//         prfloatf("%d\n",n*i);
//     }
// }
// float main(){
//     float n;
//     prfloatf("kiska table chahiye:");
//     scanf("%d",&n);
//     tables(n);
//     return 0;
// }
             /* find sq of number */
// #include<math.h>
// float square(float n);
// float square(float n){
//     return pow(n,2);
// }
// int main(){
//     float n;
//     printf("enter n:");
//     scanf("%f",&n);
//     float val=square(n);
//     printf("square of a number:%f\n",val);
//     return 0;
// } 

// void square(float a);
// void rectangle(float l,float b);
// void circle(float r);
// void square(float a){
//     printf("area of square:%f\n",a*a);
//     printf("\n");
// }
// void rectangle(float l,float b){
//     printf("area of rectangle:%f\n",l*b);
//     printf("\n");
// }
// void circle(float r){
//     float pi=3.14;
//     printf("area of circle:%f\n",pi*r*r);
//     printf("\n");
// }
// int main(){
//     float a,l,b,r;
//     printf("enter side of square:");
//     scanf("%f",&a);
//     square(a);

//     printf("enter length of rectange:");
//     scanf("%f",&l);
//     printf("enter breadth of rectangle:");
//     scanf("%f",&b);
//     rectangle(l,b);

//     printf("enter the radius of circle:");
//     scanf("%f",&r);
//     circle(r);
    
//     return 0;
// }

                     /* finding sum till n using recursions*/
// int sum(int n);
// int sum(int n){
//     if (n==1){
//         return 1;
//     }else{
//         int nsum=sum(n-1)+n;
//         return nsum;
//     }
// }
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     int val=sum(n);
//     printf("%d\n",val);
//     return 0;
// }
           /*factorial function*/
// int factorial(int n);
// int factorial(int n){
//     if (n==1 | n==0){
//         return 1;
//     } else{
//         int fact=factorial(n-1)*n;
//         return fact;
//     }
// }
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     int value=factorial(n);
//     printf("factorial=%d\n",value);
//     return 0;
//}  
      /* stack overflow:
      when a progranm tries to use more memory space in the call stack 
      than, that has been alloted to that stack*/


               /* celsius to fahrenheit*/   // F=(C*9/5)+32
// float converter(float c);
// float converter(float c){
//     return (c*1.8)+32;
// }                
// int main(){
//     float c;
//     printf("enter temperature in celsius:");
//     scanf("%f",&c);
//     float f=converter(c);
//     printf("temperatur in fahrenheit:%f\n",f);
//     return 0;
// }    



                          /*printing fibonacci series*/
// void fib(int n);
// void fib(int n){
//     int a=-1;
//     int b=1;
//     for(int i=1;i<=n;i+=1){
//         int c= a+b;
//         printf("%d\n",c);
//         a=b;
//         b=c;
//     }
// }    
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     fib(n);
//     return 0;
// }

                                     /* sum of digits of a number */
// #include<math.h>
// int sod(int num);
// int sod(int num){
//     int sum=0;
//     while(num!=0){
//         int remainder=num%10;
//         sum+=remainder;
//         num= floor(num/10);
//     }return sum;
// }
// int main(){ 
//     int num;
//     printf("enter your number:");
//     scanf("%d",&num);
//     int sumod=sod(num);
//     printf("sum of digits=%d\n",sumod);
//     return 0;
// }


#include<stdio.h>

int fibonacci(int n){
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n,nthterm;
    printf("enter n:");
    scanf("%d",&n);
    if(n>=1){
        for(int i=1;i<=n;i++){
            nthterm=fibonacci(i);
            printf("%d\t",nthterm);
        }
    }
    else{
        printf("enterted invalid no. of terms\n");
    }
    printf("\n");
    return 0;
}