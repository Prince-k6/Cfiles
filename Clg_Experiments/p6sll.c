//singly linked list SLL
/*
6. Design, Develop and Implement a menu driven Program in C for the following operations on Singly 
Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL (Demonstration of stack)
e. Exit.

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char usn[20];
    char name[20];
    char branch[20];
    int sem;
    char phno[20];
    struct node *next;
};

struct node *head=NULL;

struct node *createNode(){
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(new==NULL){
        printf("memory allocation failed\n");
        exit(0);
    }
    printf("enter usn:");
    scanf("%s",new->usn);
    printf("enter name:");
    scanf("%s",new->name);
    printf("enter branch:");
    scanf("%s",new->branch);
    printf("enter sem:");
    scanf("%d",&new->sem);
    printf("enter phno:");
    scanf("%s",new->phno);
    new->next=NULL;
    return new;
}
//a.creting a SLL of N stduents
void create_SLL(int n){      //n->no. of students
    for(int i=0;i<n;i++){
        printf("-----Enter student%d details-----\n",i+1);
        struct node *new=createNode();
        new->next=head;
        head=new;
    }
}
//b.display the status and count the number of students in it
void display(){
    if(head==NULL){
        printf("SLL is empty\n");
        return;
    }
    int count=0;
    struct node *temp=head;
    while(temp!=NULL){
        count++;
        printf("----student%d Deatils----\n",count);
        printf("USN:%s\n",temp->usn);
        printf("NAME:%s\n",temp->name);
        printf("BRANCH:%s\n",temp->branch);
        printf("SEM:%d\n",temp->sem);
        printf("PHNO:%s\n",temp->phno);
        temp=temp->next;
    }
    printf("student count in SLL: %d\n",count);
}
//c.insertion at end of SLL
void insert_atend(){
    struct node *new=createNode();
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    new->next=NULL;
    printf("usn %s inserted at end\n",new->usn);
}
//c.deletion at end of SLL
void delete_atend(){
    if(head==NULL){
        printf("SLL is empty\n");
        return;
    }
    struct node *p=NULL;
    struct node *temp=head;
    while(temp->next!=NULL){
        p=temp;
        temp=temp->next;
    }
    p->next=NULL;
    printf("usn %s deleted at end\n",temp->usn);
    free(temp);
    temp=NULL;    //to remove garbage values

}
//d.insert at front [demonstration of stack push]
void insert_atfront(){
    struct node *new=createNode();
    new->next=head;
    head=new;
    printf("usn %s inserted at front\n",new->usn);
}
//d.delete at front [demostration of stack pop]
void delete_atfront(){
    if(head==NULL){
        printf("SLL is empty\n");
        return ;
    }
    struct node *temp=head;
    head=head->next;
    printf("usn %s deleted at front\n",temp->usn);
    free(temp);
    temp=NULL;
}

int main(){
    int n,choice;
    printf("1.create N studnet SLL\n");
    printf("2.display\n");
    printf("3.insert at end\n");
    printf("4.delete at end\n");
    printf("5.indert at front(stack push)\n");
    printf("6.delete at front(stack pop)\n");
    printf("7.Exit\n");
    while(choice!=7){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter how many students you want:");
                scanf("%d",&n);
                create_SLL(n);
                printf("----SLL of %d students created successfully-----\n",n);
                break;
            case 2:
                printf("--------------Student Details---------------\n");
                display();
                break;
            case 3:
                insert_atend();
                break;
            case 4:
                delete_atend();
                break;
            case 5:
                insert_atfront();
                break;
            case 6:
                delete_atfront();
                break;
            case 7:
                printf("exiting program....\n");
                exit(0);
            default:
                printf("enter a valid choice\n");
                break;
        }
    }
    return 0;
}