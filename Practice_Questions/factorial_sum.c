//find (1!/1)+(2!/2)+(3!/3)+(4!/4).....

#include<stdio.h>
//calculating factorial
int factorial(int a){                       
    if (a==0){
        return 1;
    }                                  
    else{
        int f=1;
        for(int i=1;i<=a;i++){
            f*=i;
        }
        return f;
    }
}
int main(){
    int n,sum=0;
    printf("enter n:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=factorial(i)/i;
    }
    printf("answer=%d\n",sum);
    return 0;
}