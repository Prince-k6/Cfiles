#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;
int order[MAX], top_idx;

void DFS(int v) 
{
    visited[v] = 1;
    int i;
    for(i=0; i<n; i++) 
      {
        if(adj[v][i] && !visited[i]) 
          {
            DFS(i);
          }
      }
    order[--top_idx] = v;
}

void topological_sort() 
{
    int i;
    top_idx = n;
    for(i=0; i<n; i++) 
     {
        visited[i] = 0;
     }

    for(i=0; i<n; i++)
    {
        if(!visited[i]) 
          {
            DFS(i);
          }
     }
}

int main() 
{
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(i=0; i<n; i++)
   {
        for(j=0; j<n; j++)
       {
            scanf("%d", &adj[i][j]);
        }
    }
    topological_sort();
    printf("Topological ordering of vertices:\n");
    for(i=0; i<n; i++) 
   {
        printf("%d ", order[i]);
    }
    printf("\n");
    return 0;
}