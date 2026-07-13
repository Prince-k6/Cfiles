#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int n,cost[9][9],parent[9];         //no.of vertices, cost adj matrix, parent
int ne = 1,minCost=0;               // no of edges in mst and minCost

int find(int i){
    while(parent[i]!=-1){
        i = parent[i];
    }
    return i;
}

bool uni(int a, int b){
    int u = find(a);      //find the parent of uth node
    int v = find(b);      // find the parent of vth node
    if(u != v){
        parent[b] = a;
        return true;
    }
    return false;
}

int main(){
    n = 5;
    //if cost[i][j] = 0 then make cost[i][j] = 999;
    int cost[5][5] = {
        {999, 2, 999, 6, 999},
        {2, 999, 3, 8, 5},
        {999, 3, 999, 999, 7},
        {6, 8, 999, 999, 9},
        {999, 5, 7, 9, 999}
    };
    //sabka parent initially null hoga
    for(int i=0; i<=n;i++){
        parent[i] = -1;
    }

    printf("The edges in a minimum spanning tree are:\n");
    while(ne < n){
        //sabse pahle minimum cost/edge find krunga overall graph me
        int min = 999;
        int a,b;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if(uni(a,b)){      // if they doesn't belong to same component return true ans print the edge
            printf("%d edge(%d,%d) = %d\n",ne++,a,b,min);
            minCost += min;
        }
        cost[a][b] = cost[b][a] = 999;     //so that same edge doesn't repeat itself
    }
    printf("minimum cost of spanning tree : %d\n",minCost);
    return 0;
}