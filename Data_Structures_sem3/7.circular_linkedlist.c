//circular linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

//Traversing
void display(struct node *head){
    struct node *ptr=head;
    while(ptr->next!=head){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
    printf("\n");
}
                                              //insertion
//1.insert at front
struct node *insert_at_front(struct node *head,int val){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=head){
        p=p->next;       
    }
    p->next=ptr;
    ptr->data=val;
    ptr->next=head;
    head=ptr;
    return head;
}
//2.insert at end
struct node *insert_at_end(struct node *head,int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;ptr->data=val;
    return head;
}
                                                //Deletion
//1.delete at front
struct node *delete_at_front(struct node *head){
    struct node *p=head;
    struct node *q=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=head->next;
    head=head->next;
    free(q);
    q=NULL;
    return head;
}
//2.delete at end
struct node *delete_at_end(struct node *head){
    struct node *q=NULL;
    struct node *p=head;
    while(p->next!=head){
        q=p;
        p=p->next;
    }
    q->next=head;
    free(p);
    p=NULL;
    return head;
}

struct node *createNode(int val){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
int main(){
    struct node *head=createNode(4);
    struct node *first=createNode(3);
    struct node *second=createNode(6);
    struct node *third=createNode(1);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=head;

    //using only one node
    // struct node *head=(struct node*)malloc(sizeof(struct node));
    // head->data=8;
    // head->next=head;

    printf("\n----TRAVERSAL----\n");
    
    display(head);

    printf("\n----INSERTION----\n");
    //inserting at front
    head=insert_at_front(head,44);
    display(head);
    //insert at end
    head=insert_at_end(head,55);
    display(head);

    printf("\n------DELETION----\n");
    //delete at front
    head=delete_at_front(head);
    display(head);
    //delete at end
    head=delete_at_end(head);
    display(head);
    return 0;
}

