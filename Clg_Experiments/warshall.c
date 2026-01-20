#include<stdio.h>
#include<stdlib.h>

// int adj[4][4]={
//     {0,1,1,0},
//     {0,0,0,0},
//     {0,0,0,1},
//     {1,0,0,0}
// };
// int n=4;

int adj[5][5]={
    {0,1,0,0,1},
    {1,0,1,1,0},
    {0,1,0,1,1},
    {0,1,1,0,1},
    {1,0,1,1,0}
};
int n=5;             //no of cities/nodes



void display(int mat[n][n],int n){          //n->matrix size
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
}
void warshall(){     //n->no. of nodes/cities
    int p[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==0){
                p[i][j]=0;
            }else{
                p[i][j]=1;
            }
        }
    }
    display(p,n);
    printf("\n");
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                p[i][j]=p[i][j]|(p[i][k] & p[k][j]);       //bitwise & and |  : to find if path exist through k
            }
        }
    }
    printf("Transitive closure\n");
    display(p,n);
}

int main(){
    warshall();
    return 0;
}
