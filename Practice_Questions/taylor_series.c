//taylor series approximation
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int fact(int m){
    int i,f=1;
    for(i=1;i<=m;i++){
        f*=i;
    }
    return f;
}

void main(){
    int x,n,i;
    float rad,res,sum=0;
    printf("enter degree:");
    scanf("%d",&x);
    printf("enter number of terms:");
    scanf("%d",&n);
    rad=(3.142/180.0)*x;
    for(i=1;i<=n;i+=2){
        if((i-1)%4==0){
            sum=sum+pow(rad,i)/fact(i);
        }else{
            sum=sum-pow(rad,i)/fact(i);
        }
    }
    printf("calculated sin(%d)=%f\n",x,sum);
    printf("library sin(%d)=%f\n",x,sin(rad));
}