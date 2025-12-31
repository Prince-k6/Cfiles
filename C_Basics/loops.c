#include<stdio.h>
#include<math.h>

                                 /*FOR LOOP*/
// int main(){
//     for(int i=1;i<=5;i++){
//         printf("%d\n",i);
//     }
//     return 0;
// }

                              /* print a to z */
// int main(){
//     for(char i='a';i<='z';i++){
//         printf("%c\n",i);
//     }
//     return 0;
// }
 
                              /*while loop*/
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);

//     int i=1,sum=0;
//     while (i<=n){
//         printf("%d\n",i);
//         // sum+=i;
//         i+=1;
//     }
//     // printf("%d\n",sum);
//     return 0;
// }

                          /* do while loops*/

// int main(){
//     int n;
//     printf("enter n :");
//     scanf("%d",&n);
//     printf("n | sum till n\n");
//     printf("--|-----------\n");

//     int i=1,sum=0;
//     do{
//         sum+=pow(i,3);
//         printf("%d",i);
//         printf(" | ");
//         printf("%d\n",sum);
//         i+=1;
//     } while(i<=n);
//     // printf("%d\n",sum);
//     return 0;
//}

                            /*sum till n st. order*/
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     int i=1,sum=0;
//     do{
//         sum+=i;
//         i=i+1;
//     } while(i<=n);
//     printf("%d\n",sum);
//     return 0;
// }

                            /*sum till 1 from n*/
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);
//     int i=n,sum=0;
//     do{
//         printf("%d\n",i);
//         sum+=i;
//         i-=1;
//     } while(i>=1);
//     printf("-----\n");
//     printf("%d\n",sum);
//     return 0;

// }


                          /*tables*/
// int main(){
//     int n;
//     printf("enter n:");
//     scanf("%d",&n);

//     for(int i=1;i<=10;i+=1){
//         printf("%d\n",n*i);
//     }
//     return 0;
// }

                  /*take input until user enters an odd number*/
// int main(){
    
//     int i=0;
//     while(i==0){
//         int n;
//         printf("enter n:");
//         scanf("%d",&n);
//         if (n%2==0){
//             break;
//         } else{
//             continue;
//         }

//     }return 0;
// }


                    /*print odd numbers between a given range*/
// int main(){
//     int a,b,i;
//     printf("enter a:");
//     scanf("%d",&a);
//     printf("enter b:");
//     scanf("%d",&b);
//     for(i=a;i<=b;i+=1){
//         if (i%2!=0){
//             printf("%d\n",i);
//         }
//     }return 0;
// }

                      /*factorial using while loop*/
// int main(){
//     int n, f=1;
//     printf("enter n:");
//     scanf("%d",&n);
//     if (n==0 | n==1){
//         printf("factorial=1");
//     }else if (n>0){
//         int i=n;
//         while(i>1){
//             f*=i;
//             i-=1;
//         }printf("factorial:%d\n",f);
//     }return 0;
// }
                                /*factorial using for loop*/
                //factorial for larger numbers cannot be calculated due to "stack overflow"
int main(){
    int n, f=1;
    printf("enter n:");
    scanf("%d",&n);
    if (n==0 | n==1){
        printf("factorial=1");
    }else if (n>1){
        for(int i=1;i<=n;i+=1){
            f*=i;
        }printf("factorial:%d\n",f);
    }return 0;
}