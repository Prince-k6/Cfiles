//write a c program for ackermann function
#include<stdio.h>

int akermann(int m,int n){
    if(m==0){
        return n+1;
    }else if(m>0 && n==0){
        return ackermann(m-1,1);
    }else if(m>0 && n>0){
        return ackermann(m-1,ackermann(m,n-1));
    }
}

int main(){
    int m,n;
    printf("enter m and n:");
    scanf("%d%d",&m,&n);
    int value=ackermann(m,n);
    printf("Result:%d",value);
}