//implemenation of a queue using array
/*

rear end --> insertion
front end-->deletion
            •full conditon : rear==size-1
            •empty condition : front==-1
            •one element condition : front==rear

*/

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
    if(q->f==-1){                              //empty condition : front==-1
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q,int val){               //insertion-->rear end
    if(q->r==q->size-1){    //if full
        printf("queue overflow\n");
        return;
    }
    else if(q->f==-1){       //if empty    
        q->f=q->r=0;
    }
    else{
        q->r++;
    }
    q->arr[q->r]=val;
}

void dequeue(struct queue *q){ 
    int val;                      //deletion-->front end
    if(q->f==-1){  //if empty
        printf("queue underflow\n");
        return;
    }else if(q->f==q->r){
        val=q->arr[q->f];
        q->f=q->r=-1;
    }else{
        val=q->arr[q->f];
        q->f++;
    }
    printf("%d deleted\n",val);
}
void display(struct queue *q){
    if(q->f==-1){
        printf("queue is empty\n");
        return;
    }
    for(int i=q->f;i<=q->r;i++){
        printf("%d\t",q->arr[i]);
    }
    printf("\n");
}

int main(){
    struct queue q;
    q.size=5;
    q.r=q.f=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    if (isempty(&q)){
        printf("queue is empty\n");
    }
    else{
        printf("queue is not empty\n");
    }
    enqueue(&q,10);
    enqueue(&q,15);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,60);
    display(&q);
    if (isempty(&q)){
        printf("queue is empty\n");
    }else{
        printf("queue is not empty\n");
    }
    if (isfull(&q)){
        printf("queue is full\n");
    }
    else{
        printf("queue is not full\n");
    }
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    
}

