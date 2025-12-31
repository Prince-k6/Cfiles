//implementing circular queue
#include<stdio.h>
#include<stdlib.h>

struct circular_queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isempty(struct circular_queue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct circular_queue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct circular_queue *q,int val){
    if((q->r+1)%q->size==q->f){
        printf("queue overflow\n");
    }else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}

int dequeue(struct circular_queue *q){
    if(q->r==q->f){
        printf("queue underflow. ");
        return -1;
    }else{
        q->f=(q->f+1)%q->size;
        return q->arr[q->f];
    }
}
void display(struct circular_queue *q){
    int i=q->f; 
    while(i!=q->r){
        printf("%d\t",q->arr[i+1]);
        i=(i+1)%q->size;
    }
    printf("\n");
}



int main(){
    struct circular_queue *cq=(struct circular_queue *)malloc(sizeof(struct circular_queue));
    int actual_size=5; //actual size=5
    cq->size=actual_size+1;  //circular queue size one greater because one empty space is required to make the difference b/w front and rear end
    
    cq->f=cq->r=0;         //fornt and rear are initialised with 0

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
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));
    printf("deleted:%d\n",dequeue(cq));

    display(cq);
    return 0;
}