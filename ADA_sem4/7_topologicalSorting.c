#include <stdio.h>
#include<stdbool.h>

#define MAX 100

int adj[6][6] = {
        {0,0,1,1,0,0},
        {0,0,0,0,1,0},
        {0,1,0,1,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,0,0},
        {0,1,0,0,1,0}
    };
// int adj[MAX][MAX];
int visited[MAX];
int n=6;
int order[MAX], top_idx;

void DFS(int u){
    visited[u] = true;
    for(int v=0; v<n; v++){
        if(adj[u][v] && !visited[v]){
            DFS(v);
        }
    }
    order[--top_idx] = u;     
}

void topological_sort(){
    top_idx = n;
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main() {
    // int i, j;
    // printf("Enter the number of vertices: ");
    // scanf("%d", &n);
    // printf("Enter the adjacency matrix:\n");
    // for(i=0; i<n; i++){
    //   for(j=0; j<n; j++){
    //     scanf("%d", &adj[i][j]);
    //   }
    // }
    topological_sort();
    printf("Topological ordering of vertices:\n");
    for(int i=0; i<n; i++){
        printf("%d ", order[i]);
    }
    printf("\n");
    return 0;
}

