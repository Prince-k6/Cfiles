//linked list node creation and traversal
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

//linked list traversal
void display(struct node *head){      
    struct node *ptr=head; 
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}
                                        //linked list insertion
//1.front insertion
struct node* insert_at_front(struct node *head,int val){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=val;
    return ptr; 
}
//2.insert at index (insertion in between)
struct node* insert_at_index(struct node *head,int index,int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));   //node that'll be inserted
    struct node* p=head;   
    int count=0;
    while(count!=index-1){
        p=p->next;
        count++;
    }
    ptr->next=p->next; ptr->data=val;
    p->next=ptr;
    return head;
}
//3.insert at end
struct node* insert_at_end(struct node *head,int val){
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=val;
    ptr->next=NULL;
    return head;
}
//4.insert after node
struct node* insert_after(struct node* head,struct node *prevNode,int val){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    ptr->data=val;
    return head;
}

                                    //deletion in linked list
//5.deleting first node
struct node* delete_first(struct node* head){
    if(head==NULL){
        return NULL;
    }
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    return head;
}
//6.deleting a node in b/w
struct node *delete_at_index(struct node *head,int index){
    if(head==NULL){
        return NULL;
    }
    struct node *q=NULL;
    struct node *p=head;
    int i=0;
    while(i!=index-1){
        q=p;
        p=p->next;
        i++;
    }
    q->next=p->next;
    p->next=NULL;
    free(p);
    p=NULL;  // to remove garbage values also
    return head;
}
//7.deleting last node
struct node *delete_at_end(struct node *head){
    struct node *p=head->next;
    struct node *q=head;
    while(p->next!=NULL){
        p=p->next;
        q=q->next;
    }
    q->next=NULL;
    free(p);
    p=NULL;
    return head;
}
//8.deleting a node with given value
struct node *delete_with_value(struct node *head,int value){
    struct node *p=head->next;
    struct node *q=head;
    while(p->data!=value && p->next!=NULL){
        p=p->next;
        q=q->next;
    }
    q->next=p->next;
    p->next=NULL;
    free(p);
    p=NULL;  // to remove garbage values also
    return head;
}

struct node *createNode(int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
int main(){
    //created 3 nodes in heap memory cause of dynamic memory allocation
    struct node *head=createNode(7);
    struct node *second=createNode(11);
    struct node *third=createNode(66);
    struct node *fourth=createNode(88);

    //link first and second node
    head->next=second;

    //link second and third node
    second->next=third;

    //link third and fourth node
    third->next=fourth;

    printf("\n----------Traversal---------\n");
    //traversing the linked list
    display(head);

    printf("\n----------Insertion---------\n");
    //inserting at front
    head=insert_at_front(head,3);
    display(head);
    //inserting at index (in between nodes) -using index
    head=insert_at_index(head,2,54);
    display(head);
    //inserting at end
    head=insert_at_end(head,100);
    display(head);
    //inserting after a node (insert 24 after second node)
    head=insert_after(head,second,24);
    display(head);

    printf("\n----------Deletion---------\n");
    //deleting first node
    head=delete_first(head);
    display(head);
    //deleting at index (in between nodes) -using index
    head=delete_at_index(head,3);
    display(head);
    //deleting last node
    head=delete_at_end(head);
    display(head);
    //deleting a node with given value
    head=delete_with_value(head,54);
    display(head);
    return 0;
}


