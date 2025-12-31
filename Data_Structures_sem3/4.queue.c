//implemenation of a queue using array
/*

rear end --> insertion
front end-->deletion

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

int main(){
    struct queue q;
    q.size=7;
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

