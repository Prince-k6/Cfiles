#include<stdio.h>
int main(){
    //first take order of matrices and check condition
    int m,n,p,q;
    printf("enter order of matrix A:\n");
    scanf("%d%d",&m,&n);
    printf("enter order of matrix B:\n");
    scanf("%d%d",&p,&q);
    int A[m][n],B[p][q],C[m][n];
    int i,j,k;
    if(m!=p || n!=q){
        printf("Matrix addition not possible\n");
    }
    else{
        //taking matrix A & B input 
        printf("enter A:\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                scanf("%d",&A[i][j]);
            }
        }
        printf("enter B:\n");
        for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                scanf("%d",&B[i][j]);
            }
        }
        //printing matrix A & B
        printf("Matrix A\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d\t",A[i][j]);
            }
            printf("\n");
        }
        printf("Matrix B\n");
         for(i=0;i<p;i++){
            for(j=0;j<q;j++){
                printf("%d\t",B[i][j]);
            }
            printf("\n");
        }
        //assigning zeros to matrix C and adding elements
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                    C[i][j]=A[i][j]+B[i][j];
            }
        }
        //printingC
        printf("matrix C:\n");
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                printf("%d\t",C[i][j]);
            }
            printf("\n");
        }

    }
}