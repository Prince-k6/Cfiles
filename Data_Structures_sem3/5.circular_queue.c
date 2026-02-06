//implementing circular queue

/*
rear end --> insertion
front end-->deletion

full condition:         front==(rear+1)%size
empty condition:        front==-1
one element contion:    front==rear

*/


#include<stdio.h>
#include<stdlib.h>

struct circular_queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct circular_queue *q){
    if(q->f==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct circular_queue *q){
    if(q->f==(q->r+1)%q->size){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct circular_queue *q,int val){
    if(q->f==(q->r+1)%q->size){
        printf("queue overflow\n");
        return;
    }else if(q->f==-1){
        q->f=q->r=0;
    }else{
        q->r=(q->r+1)%q->size;
    }
    q->arr[q->r]=val;
}

int dequeue(struct circular_queue *q){
    int val;
    if(q->f==-1){
        printf("queue underflow. ");
        return -1;
    }else if(q->f==q->r){
        val=q->arr[q->f];
        q->f=q->r=-1;
    }else{
        val=q->arr[q->f];
        q->f=(q->f+1)%q->size;
    }
    return val;
}
void display(struct circular_queue *q){
    if(q->f==-1){
        printf("queue is empty\n");
        return;
    }
    int i=q->f; 
    while(i!=q->r){
        printf("%d\t",q->arr[i]);
        i=(i+1)%q->size;
    }
    printf("%d\n",q->arr[i]); //printing last element 
}



int main(){
    struct circular_queue *cq=(struct circular_queue *)malloc(sizeof(struct circular_queue));
    cq->size=5;
    cq->f=cq->r=-1;         //front and rear are initialised with 0
    cq->arr=(int *)malloc(cq->size*sizeof(int));

    printf("empty or not :%d\n",isempty(cq));
    enqueue(cq,20);
    enqueue(cq,30);
    enqueue(cq,40);
    enqueue(cq,50);
    enqueue(cq,60);
    enqueue(cq,70);      //queue overflow
    display(cq);
    printf("empty or not :%d\n",isempty(cq));
    printf("full or not :%d\n",isfull(cq));
    printf("deleted:%d\n",dequeue(cq));      //20
    printf("deleted:%d\n",dequeue(cq));      //30
    printf("deleted:%d\n",dequeue(cq));      //40
    printf("deleted:%d\n",dequeue(cq));      //50
    printf("deleted:%d\n",dequeue(cq));      //60
    printf("deleted:%d\n",dequeue(cq));      //underflow
    printf("deleted:%d\n",dequeue(cq));      //underflow
    display(cq);
    return 0;
}