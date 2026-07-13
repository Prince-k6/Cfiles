#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX 100
// int n;    //no of vertices
// int graph[MAX][MAX];

int n = 4;
int graph[MAX][MAX] = {
    {0, 2, 5, 0},
    {2, 0, 1, 6},
    {5, 1, 0, 2},
    {0, 6, 2, 0}
};
int dist[MAX];
int visited[MAX];

int getMinDistVertex(){
    int min_dist = INT_MAX;
    int min_vertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i] < min_dist){
            min_dist = dist[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}


void dijikstra(int start){
    //initialisation
    for(int i=0;i<n;i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    //exploration
    for(int i=0;i<n-1;i++){
        int u = getMinDistVertex();
        visited[u] = true;

        //relaxtation
        for(int v=0;v<n;v++){
            if(graph[u][v] && !visited[v] && dist[u] != INT_MAX){
                int new_dist = dist[u]+graph[u][v];
                if(new_dist < dist[v]){
                    dist[v] = new_dist;
                }
            }
        }
    }

}

int main(){
    // printf ("enter n:");
    // scanf("%d",&n);

    // printf("enter the adjacency matrix:\n");
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n; j++){
    //         scanf("%d",&graph[i][j]);
    //     }
    // }

    int start;
    printf("enter the starting node:");
    scanf("%d",&start);

    dijikstra(start);

   printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: %d\n", i, dist[i]); // Guaranteed to not be inf
    }
    return 0;
}
