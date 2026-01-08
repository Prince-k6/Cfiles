#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct queue *q){
    if(q->f==q->r){                       //empty condition : rear==front
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val){
    if(q->r==q->size-1){                  //insertion-->rear end
        printf("queue is full");
        return;
    }
    q->r++;
    q->arr[q->r]=val;
}
int dequeue(struct queue *q){
    if(isempty(q)){                       //deletion-->front end
        return -1;
    }
    q->f++;
    int val=q->arr[q->f];
    return val;
}

int adj[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };
int visited[20];
int numCities;

void bfs_traversal(int start){
    struct queue q;
    q.size=100;
    q.f=-1;
    q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));          // Allocate memory for the queue array
   
    for(int i=0;i<numCities;i++){   //initialize all the visited nodes to zero
        visited[i]=0;
    }

    int node;
    printf("%d ",start);
    visited[start]=0;
    enqueue(&q,start);            //enqueue starting node for exploration
    while(!isempty(&q)){
        node=dequeue(&q);         //dequeue explored node
        for(int j=0;j<numCities;j++){
            if(adj[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(&q,j);   //enqueue for exploration
            }
        }
    }
    printf("\n");
    free(q.arr);                 // Free allocated memory
}

int main(){
    numCities=7;
    int start=2;
    bfs_traversal(start);
    return 0;
}