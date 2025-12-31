// fibonacci using recurssion
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
