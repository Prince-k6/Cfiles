#include<stdio.h>
#define max 100

int adj[max][max];
int visited[max];
int n;
int order[max], top_idx;

void topological_sort(){
    top_idx = n;
    for(int i =0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}