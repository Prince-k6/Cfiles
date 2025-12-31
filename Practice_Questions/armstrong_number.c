//check whether a number is armstrong or not
#include<stdio.h>
#include<math.h>
int armstrong(int n){
    int i=n;
    int sum=0,r;
    while(i>0){
        r=i%10;
        sum+=pow(r,3);
        i=i/10;
    }
    if (sum==n){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int n=345;
    int check=armstrong(n);
    if (check==1){
        printf("%d is an armstrong number\n",n);
    }
    else{
        printf("%d is not an armstrong number\n",n);
    }
    return 0;
}