//bfs traversal

#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q){
    if(q->r==q->size-1){                     //full conditon : rear==size-1
        return 1;
    }
    return 0;
}
int isempty(struct queue *q){
    if(q->f==q->r){                              //empty condition : rear==front
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){               //insertion-->rear end
    if(q->r==q->size-1){
        printf("queue is full\n");
    }else{
        q->r++;
        q->arr[q->r]=val;
    }
}

void dequeue(struct queue *q){                       //deletion-->front end
    if((q->f==q->r)||((q->f==-1)&&(q->r==-1))){
        printf("queue is empty\n");
        // return -1;
    }else{
        q->f++;
        int val=q->arr[q->f];
        // return val;
        printf("%d removed\n",q->arr[q->f]);
    }

}
void display(struct queue *q){
    if((q->f==q->r)||((q->f==-1)&&(q->r==-1))){
        printf("queue is empty\n");
    }
    else{
        int i=q->f+1;;
        while(i<=q->r){
            printf("%d\t",q->arr[i]);
            i++;
        }
    }
    printf("\n");
}
/*------------------------------------------------------------------------------------------------------------*/
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

int main(){
    struct queue *q;
    q->f=-1;
    q->r=-1;
    create_graph();
    for(int i=0;i<numCities;i++){       //initialise visited with zero 
        visited[i]=0;
    }

    return 0;

   
    
}