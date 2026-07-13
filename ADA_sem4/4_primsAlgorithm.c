//prims algorithm practice
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>      //for INT_MAX, INT_MIN
#include<stdbool.h>

#define V 5

int minKey(int key[V], int mstSet[V]){
    int min = INT_MAX, min_index;
    for(int i=0; i<V ;i++){
        if(key[i] < min && !mstSet[i]){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int parent[V], int graph[V][V]){
    int totalCost = 0;
    for(int i=1; i<V; i++){
        printf("%d edge(%d, %d) = %d\n",i,i,parent[i],graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("minimum cost of spanning tree: %d \n", totalCost);
}

void primsMST(int graph[V][V]){
    int parent[V];           //to store the final MST 
    int key[V];              //to find the minimum value of an edge
    int mstSet[V];           //to keep a track of which all nodes are included in the mst

    for(int i=0; i<V;i++){
        mstSet[i] = false;
        key[i] = INT_MAX;
    }
    key[0] = 0;
    parent[0] = -1;

    for(int count=1 ; count<V; count++){    //loop only for V-1 edges
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for(int v=0; v<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);

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