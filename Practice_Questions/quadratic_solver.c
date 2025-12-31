#include<stdio.h>
#include<math.h>

int main(){
    float a,b,c;
    float D;
    float X1,X2;
    printf("enter the coeff.of X^2:");
    scanf("%f",&a);
    if(a==0){
        printf("invalid input...try again\n");
    }
    else{
        printf("enter coeff. of X:");
        scanf("%f",&b);
        printf("enter constant:");
        scanf("%f",&c);

        D=b*b-4*a*c;

        if(D>0){
            printf("Roots are real and distinct\n");
            X1=(-b+D)/(2*a);
            X2=(-b-D)/(2*a);
            printf("X1=%.2f & X2=%.2f\n",X1,X2);
            
        }
        else if(D==0){
            printf("Roots are real and equal\n");
            X1=X2=-b/(2*a);
            printf("X1=%.2f & X2=%.2f\n",X1,X2);
        }
        else{
            printf("Roots are imaginary\n");
            printf("X1=%.2f+i%.2f\n",-b/(2*a),sqrt(D));
            printf("X2=%.2f-i%.2f\n",-b/(2*a),sqrt(D));
        }
    }
    return 0;
}