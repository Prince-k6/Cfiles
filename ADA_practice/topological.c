//topological ordering 
// it is only applicable for direct graph

#include<stdio.h>
#include<stdbool.h>

#define MAX 100

int n = 6;
int adj[6][6] = {
        {0,0,1,1,0,0},
        {0,0,0,0,1,0},
        {0,1,0,1,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,0,0},
        {0,1,0,0,1,0}
    };
// int n,adj[MAX][MAX]
int visited[MAX];
int order[MAX];
int top_index;

void DFS(int i){
    visited[i] = true;
    for(int j=0; j<n; j++){
        if(adj[i][j] && !visited[j]){
            DFS(j);
        }
    }
    order[--top_index] = i;
}

void topological_sort(){
    top_index = n;
    for(int i=0; i<n ;i++){
        visited[i] = false;
    }
    for(int i=0; i<n ;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main(){
    //in exam take as input or define the graph globally itself
    topological_sort();
    for(int i=0; i<n ;i++){
        printf("%d  ",order[i]);
    }
    printf("\n");
    return 0;
}