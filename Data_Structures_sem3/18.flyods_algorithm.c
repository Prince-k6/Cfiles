//floyds algorithm
#include<stdio.h>
#include<stdlib.h>

#define infinity 999

int adj[20][20];
int n;

// int adj[4][4]={
//     {0,1,1,0},
//     {0,0,0,1},
//     {0,1,0,0},
//     {1,0,1,0}
// };
// int n=4;

// int adj[4][4]={             //weighted adjacency matrix
//     {0,3,3,0},
//     {0,0,0,1},
//     {0,3,0,0},
//     {2,0,5,0}
// };
// int n=4;                   //no of cities/nodes

void create_graph(int n){

    if(n>20 || n<=0){
        printf("invalid cities\n");
        exit(0);
    }
    printf("enter adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
}
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
    printf("enter the number of nodes:");
    scanf("%d",&n);

    create_graph(n);
    printf("Adjacency matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

    floyds();
    return 0;
}