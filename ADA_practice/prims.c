#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define V 5

int minKey(int key[],int mstSet[]){
    int min = 999, min_index;
    for(int i=0;i<V;i++){
        if(!mstSet[i] && key[i]<min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[V], int graph[V][V]){
    printf("the minimum spanning tree edges are:\n");
    int minCost = 0;
    for(int i=1;i<V;i++){
        printf("%d edge(%d,%d) = %d\n",i,i,parent[i], graph[i][parent[i]]);
        minCost+=graph[i][parent[i]];
    }
    printf("the mincost of the MST is %d\n",minCost);
}
void primsMST(int graph[V][V]){
    int parent[V];
    int key[V];
    int mstSet[V];

    //initialisation
    for(int i=0;i<V;i++){
        key[i] = 999;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    //exploration
    for(int i=0;i<V-1;i++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;

        //exploration
        for(int v=0;v<V;v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMST(parent,graph);
}

int main(){
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primsMST(graph);
    return 0;
}