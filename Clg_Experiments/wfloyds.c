#include<stdio.h>
#include<stdlib.h>

int infinity=99;

int adj[4][4]={
    {0,1,1,0},
    {0,0,0,1},
    {0,1,0,0},
    {1,0,1,0}
};
int n=4;

void display(int mat[n][n],int n){          //n->matrix size
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
void floyds(){     //n->number of nodes/cities
    int p[n][n];       
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==0){
                p[i][j]=infinity;
            }else{
                p[i][j]=adj[i][j];
            }
        }
    }
    display(p,n);
    printf("\n");
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=min(p[i][j],p[i][k]+p[k][j]);
            }
        }
    }
    printf("Shortest distance matrix\n");
    display(p,n);
}

int main(){
    floyds();

    return 0;
}