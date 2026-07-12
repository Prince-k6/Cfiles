#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,cost[9][9],parent[9];
int ne=1, minCost=0;     //no. of edges , minimum cost


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
        parent[b] = a;
        return true;
    }
    return false;
}
int main(){
    n = 5;
    int cost[5][5] = {
        {999, 2, 999, 6, 999},
        {2, 999, 3, 8, 5},
        {999, 3, 999, 999, 7},
        {6, 8, 999, 999, 9},
        {999, 5, 7, 9, 999}
    };

    //parent ko initialise with -1;
    for(int i=0; i<n;i++){
        parent[i] = -1;
    }

    printf("The edges in a minimum spanning tree are:\n");
    while(ne < n){
        int min =999;  //to store the cost on each iteration
        int a,b;      //to store the edge on each iteration

        for(int i=0; i<n ;i++){
            for(int j=0;j<n;j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        if(uni(a,b)){
            printf("%d edge(%d,%d) = %d\n",ne++,a,b,min);
            minCost+=min;
        }
        cost[a][b] = cost[b][a] = 999;    //so that it doesn't get included once again
    }
    printf("minimum cost of spanning tree : %d\n",minCost);
    return 0;
}