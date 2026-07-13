#include<stdio.h>
#include<stdbool.h>


#define MAX 100
int n = 5;
int cost[MAX][MAX] = {
        {999, 2, 999, 6, 999},
        {2, 999, 3, 8, 5},
        {999, 3, 999, 999, 7},
        {6, 8, 999, 999, 9},
        {999, 5, 7, 9, 999}
};
int parent[MAX];
int ne =1, minCost = 0;     //no of edges and minCost

int find(int i){
    while(parent[i]!=-1){
        i = parent[i];
    }
    return i;
}
bool uni(int a,int b){
    int u = find(a);
    int v = find(b);
    if(u!=v){
        parent[u] = v;
        return true;
    }
    return false;
}

int main(){
    // printf("enter n:");
    //enter cost adjacency matrix

    //it just uses find and uniqe

    //initialisation : initially sabka parent null
    for(int i=0;i<n;i++){
        parent[i] = -1;
    }

    printf("the edges of minimum spanning tre are:\n");
    while(ne<n){
        int min = 999;
        int a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n ;j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if(uni(a,b)){
            printf("%d edge(%d,%d) = %d\n",ne++,a,b,min);
            minCost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("minimum cost of the spanning tree : %d\n",minCost);

    return 0;
}