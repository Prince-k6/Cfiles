// Write a C program to reverse a singly liked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *createNode(int data){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}
struct node *insert_atend(struct node *head,int val){
    struct node *new=createNode(val);
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->next=NULL;
    return head;
}
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node *reverse(struct node *head){
    struct node *prevnode=NULL;
    struct node *current=head;
    struct node *nextnode=NULL;
    while(current!=NULL){
        nextnode=current->next;
        current->next=prevnode;
        prevnode=current;
        current=nextnode;
    }
    head=prevnode;
    return head;
}

int main(){
    struct node *head=createNode(9);
    head=insert_atend(head,5);
    head=insert_atend(head,3);
    head=insert_atend(head,8);
    head=insert_atend(head,6);
    display(head);
    head=reverse(head);
    display(head);


    return 0;
}