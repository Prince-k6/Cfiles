//graph traversal DFS(Depth first search)
#include<stdio.h>
#include<stdlib.h>

int adj[20][20];
int visited[20];

int numCities;

void create_graph(){
    printf("enter the number of cities:");
    scanf("%d",&numCities);

    if(numCities > 20 || numCities<0){
        printf("invalid number of cities\n");
        exit(0);
    }
    printf("Enter adjacency matrix(1-directed,0-otherwise):\n");
    for(int i=0;i<numCities;i++){
        for(int j=0;j<numCities;j++){
            scanf("%d",&adj[i][j]);
        }
    }
}
void dfs(int start){
    visited[start]=1;         //mark the current node as 1 and print it
    printf("%d\t",start);
    for(int j=0;j<numCities;j++){
        if(adj[start][j]==1 && visited[j]==0){
            dfs(j);
        }
    }
}
int main(){
    create_graph();
    for(int i=0;i<numCities;i++){       //initialise visited with zero 
        visited[i]=0;
    }
    int key;
    printf("enter the start node to find the reachable node:");
    scanf("%d",&key);
    dfs(key);

    return 0; 


}