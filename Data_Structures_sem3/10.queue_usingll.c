//queues using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *f=NULL;
struct node *r=NULL;
                                    // is empty
int is_empty(){
    if(f==NULL){
        return 1;
    }
    return 0;
}
                                    //is full
int is_full(){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){            //if memory allocatio fails then overflow
        return 1;
    }
    return 0;
}
                                //count number of nodes
int count_node(){
    if(is_empty()){
        return 0;
    }
    struct node *ptr=f;
    int count=1;
    while(ptr->next!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count++;
}
                                       //display function
void display(){
    if(is_empty()){
        printf("Queue is empty\n");
        printf("total number of nodes %d\n",count_node());
        return;
    }
    struct node *ptr=f;
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    printf("total number of nodes %d\n",count_node());
}

void enqueue(int value){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if(newNode==NULL){            //if memory allocatio fails then overflow
        printf("Queue overflow\n");
    }
    if(f==NULL){           //when both front and rear are null that is queue is empty
        f=r=newNode;
        newNode->data=value;
    }else{
        r->next=newNode;
        newNode->data=value;
        newNode->next=NULL;
        r=newNode;
    }
}
void dequeue(){
    if(f==NULL){
        printf("queue underflow\n");
        return;
    }
    struct node *temp=f;
    f=f->next;
    int x=temp->data;
    printf("%d removed\n",x);
    free(temp);
}


int main(){
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();   //underflow
    
    display();
    enqueue(55);
    display();

    return 0;
}


