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
    }else{
        front=(front+1)%MAX;
    }
    deque[front]=element;
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
        front=(front+1)%MAX;
    }
    printf("deleted:%d\n",deleted);
}
int main(){

    return 0;
}