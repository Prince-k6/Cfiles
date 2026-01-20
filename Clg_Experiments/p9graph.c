//graphs
/*
9. Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the node reachable from a given starting node in a digraph using any traversal method (DFS/BFS).
*/
#include<stdio.h>
#include<stdlib.h>

int numCities;
int adj[20][20];      //adjacency matrix
int visited[20];       //for dfs traversal

void create_graph(){
    printf("enter the number of nodes/cities:");
    scanf("%d",&numCities);
    if(numCities<0 || numCities>20){
        printf("invalid number of cities\n");
        exit(0);
    }
    printf("enter adjacency matix (1->pathexist,0->otherwise)\n");
    for(int i=0;i<numCities;i++){
        for(int j=0;j<numCities;j++){
            scanf("%d",&adj[i][j]);
        }
    }
}
void display_adjM(){
    printf("Adjacency matrix of given graph\n");
    for(int i=0;i<numCities;i++){
        for(int j=0;j<numCities;j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}

void dfs(int start){
    visited[start]=1;
    printf("%d  ",start);
    for(int i=0;i<numCities;i++){
        if(adj[start][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}
int main(){
    create_graph();
    display_adjM();
    
    int start;
    printf("enter start node for dfs traversal:");
    scanf("%d",&start);
    printf("Nodes reachable:");
    dfs(start);
    printf("\n");

    return 0;
}