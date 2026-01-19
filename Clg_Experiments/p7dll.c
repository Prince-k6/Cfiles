//DLL using two pointer
/*
7. Design, Develop and Implement a menu driven Program in C for the following operations on Doubly Linked List(DLL)
of Employee Data with the fields: SSN, Name, Dept, Designation, Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    // char ssn[20];
    // char name[20];
    // char dept[20];
    // char desig[20];
    // float sal;
    // char phno[20];
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;     //always points at the start of DLL
struct node *tail=NULL;     //always points at the end of DLL

struct node *createNode(){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL){
        printf("memory allocation failed\n");
        exit(0);
    }
    //enter employee details [for now i have only take one filed data just for the sake of typing less]
    printf("enter data:");
    scanf("%d",&new->data);
    new->prev=NULL;
    new->next=NULL;
    return new;
}
//a.create a DLL of. N employee
void create_DLL(int n){       //n-> no. of employee
    for(int i=0;i<n;i++){
        printf("----Enter emp%d Details-----\n",i+1);
        struct node *new=createNode();
        if(head==NULL){
            head=new;
            tail=new;
        }else{
            tail->next=new;
            new->prev=tail;
            new->next=NULL;
            tail=new;
        }
    }
    printf("---created a DLL of %d Employees----\n",n);
}
//b.display and count the number of nodes in DLL
void display(){
    int count=0;
    struct node *temp=head;
    while(temp!=NULL){
        count++;
        printf("----Employee%d details-----\n",count);
        printf("data:%d\n",temp->data);
        temp=temp->next;
    }
    printf("Employee count:%d\n",count);
}
//c.insertion at end end of DLL
void insert_atend(){          //using tail
    struct node *new=createNode();
    if(head==NULL){
        head=new;
        tail=new;
    }else{
        tail->next=new;
        new->prev=tail;
        new->next=NULL;
        tail=new; 
        
    }
    // printf("employee with ssn %s inserted at end\n",new->ssn);

}
//c.deletion at end of DLL
void delete_atend(){
    if(head==NULL){
        printf("DLL is empty\n");
        return;
    }
    struct node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    // printf("employee with ssn %s deleted at end\n",temp->ssn);
    free(temp);
    temp=NULL;
}
//d.insertion at front of DLL
void insert_atfront(){
    struct node *new=createNode();
    if(head==NULL){
        head=new;
        tail=new;
    }else{
        new->next=head; new->prev=NULL;
        head->prev=new;
        head=new;
    }
    // printf("employee with ss %s inserted at fornt\n");
}
//d.deletion at front of DLL
void delete_atfront(){
    if(head==NULL){
        printf("DLL is empty\n");
        return;
    }else{
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        // printf("employee with ssn %s deleted at fron\n");
        free(temp);
        temp=NULL;
    }
}
//demonstarte this DLL as DEqueue
void demonstrate(){
    printf("------demonstrating as dequeue-------\n");
    printf("--1.Enqueue (at front)--\n");
    insert_atfront();
    display();

    printf("--2.Enqueue (at rear)--\n");
    insert_atend();
    display();

    printf("--3.dequeue (at front)--\n");
    delete_atfront();
    display();

    printf("--3.dequeue (at front)--\n");
    delete_atend();
    display();
}
int main(){
    int n;
    printf("enter how many employees:");
    scanf("%d",&n);
    create_DLL(n);
    display();

    insert_atend();
    display();

    delete_atend();
    display();

    insert_atfront();
    display();

    delete_atfront();
    display();

    demonstrate();
    return 0;
}

