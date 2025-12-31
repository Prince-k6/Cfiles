// WAP to get the ASCII value of a character
#include<stdio.h>       // use of header line: it provides an interface between user and os
int main(){
    char ch;
    printf("enter character:");
    scanf("%c",&ch);
    printf(" ASCII value of %c=%d\n",ch,ch);
    return 0;
}



                                        //WAP to find the sizeof int,float,double & char
// #include<stdio.h>    
// int main(){
//     printf("size of int:%lu bytes\n",sizeof(int));
//     printf("size of float:%lu bytes\n",sizeof(float));
//     printf("size of double:%lu bytes\n",sizeof(double));
//     printf("size of char:%lu bytes\n",sizeof(char));
//     return 0;
// }