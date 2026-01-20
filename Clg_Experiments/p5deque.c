//double ended queue

/*
5. Design, Develop and Implement a menu driven Program in C for the following operations on Double Ended QUEUE 
of integers(Array Implementation of Queue with maximum size MAX)
a. Perform Insertion / Deletion at front of QUEUE
b. Perform Insertion / Deletion at rear of QUEUE.
c. Display the status of Circular QUEUE
d. Exit
Support the program with appropriate functions for each of the above operations.

*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int deque[MAX];
int front=-1;
int rear=-1;
/*
empty condition->        if (front==-1 && rear==-1)
full condition->         if ((rear+1)%size==front)
one element condition->  if  (front==rear)

*/
int isempty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(front==(rear+1)%MAX){
        return 1;
    }
    return 0;
}

//insert at front
void insert_atfront(int element){
    if(isfull()){
        printf("dequeue is full\n");
        return;
    }
    if(isempty()){
        front=0;
        rear=0;
        deque[front]=element;
    }else{
        if(front==0){
            front=MAX-1;      //wrap around
        }else{
            front--;
        }
        
    }
    deque[front]=element;
    printf("%d inserted at front\n",element);
}
void insert_atrear(int x){
    if(isfull()){
        printf("dequeu overflow\n");
        return ;
    }else if(isempty()){
        front=0;
        rear=0;
    }else{
        if(rear==MAX-1){
            rear=0;
        }else{
            rear++;
        }
    }
    deque[rear]=x;
    printf("%d inserted at rear\n",x);
}

void display(){
    if(isempty()){
        printf("dequeue is empty\n");
        return;
    }
    int i=front;
    while(i!=rear){
        printf("%d\t",deque[i]);
        i=(i+1)%MAX;
    }
    printf("%d\n",deque[i]);
}
void delete_atfront(){
    if(isempty()){
        printf("deque is empty\n");
        return ;
    }
    int deleted=deque[front];
    if(front==rear){      //one element case
        front=-1;
        rear=-1;
    }else{
        if(front==MAX-1){
            front=0;
        }else{
            front++;
        }
    }
    printf("deleted:%d\n",deleted);
}
void delete_atend(){
    if(isempty()){
        printf("deque is empty\n");
        return ;
    }int deleted=deque[rear];
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        if(rear==0){
            rear=MAX-1;     //wrap around 
        }else{
            rear--;
        }
    }
    printf("deleted:%d\n",deleted);
}
int main(){
    insert_atfront(9);
    insert_atfront(8);
    insert_atfront(7);
    display();
    insert_atrear(4);
    insert_atrear(3);
    display();

    delete_atfront();
    delete_atfront();
    display();
    delete_atend();
    delete_atend();
    display();
    delete_atend();
    display();

    
    return 0;
}