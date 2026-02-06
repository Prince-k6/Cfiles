//circular queque array implementation

/*
4. Design, Develop and Implement a menu driven Program in C for the
following Operations on Circular QUEUE of integers (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above
operations.
*/

#include<stdio.h>
#include<stdlib.h>

//make the queue
#define MAX 5
int Cqueue[MAX];
int front=-1;
int rear=-1;
/*
empty condition->        if (front==-1 && rear==-1)
full condition->         if (front==(rear+1)%size)
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
/*
enqueue/insertion->rear end
dequeue/deletion->front end
*/
void enqueue(int element){   //insertin at rear end
    if(isfull()){
        printf("Queue overflow, cannot insert\n");
        return;
    }
    if(isempty()){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    Cqueue[rear]=element;
}
void dequeue(){          //deletion at front end
    int deleted;
    if(isempty()){
        printf("Queue underflow, cannot delete\n");
        return ;
    }
    if(front==rear){     //one element condition
        deleted=Cqueue[front];
        front=-1;
        rear=-1;
    }else{       //more than element
        deleted=Cqueue[front];
        front=(front+1)%MAX;
    }
    printf("Deleted:%d\n",deleted);
}

void display(){
    if(isempty()){
        printf("Circular queue is empty\n");
        return ;
    }
    int i;
    for(i=front;i!=rear;i=(i+1)%MAX){
        printf("%d\t",Cqueue[i]);
    }
    printf("%d\n",Cqueue[i]);     //print the last element
    printf("front:%d , Rear:%d",front,rear);
    printf("\n");
}

int main(){
    // enqueue(5);
    // enqueue(4);
    // enqueue(2);
    // enqueue(7);
    // display();

    // dequeue();
    // dequeue();
    // display();

    // enqueue(5);
    // enqueue(8);
    // display();
    // enqueue(6);
    // display();
    // enqueue(7);
    // display();

    int choice,element;
    printf("1.insert\n");
    printf("2.delete\n");
    printf("3.display\n");
    printf("4.Exit\n");
    while(choice!=4){
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("enter element to insert:");
            scanf("%d",&element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Queue status\n");
            display();
            break;
        case 4:
            printf("Exiting program....\n");
            exit(0);
        default:
            printf("invald choice\n");
            break;
        }
    }
    return 0;
}