//Doubly linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;


void display(struct node *head){
    struct node *ptr=head;
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

                               //doubly linked list insertion
//insert at front
struct node *insert_at_front(struct node *head,int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=val;
    ptr->next=head;
    head->prev=ptr;
    return ptr;
}
//insert at end
struct node *insert_at_end(struct node *head,int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p; ptr->data=val; ptr->next=NULL;
    return head;
}
struct node *insert_at_index(struct node *head,int index,int val){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p= head->next;
    struct node *q=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    ptr->next=p;
    p->prev=ptr;
    q->next=ptr;
    ptr->prev=q;
    ptr->data=val;
    return head;
}
                                      //Deletion in doubly linked list
//delete at front
struct node *delete_at_front(struct node *head){
    struct node *p=head->next;
    p->prev=NULL;
    free(head);
    return p;
}
//delete at end
struct node *delete_at_end(struct node *head){
    struct node *p=head->next;
    struct node *q=head;
    while(p->next!=NULL){
        p=p->next;
        q=q->next;
    }q->next=NULL;
    free(p);
    return head;

}
int main(){
    //creating the linked list with 4 nodes
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *first=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    head->prev=NULL;      head->data=5;      head->next=first;
    first->prev=head;     first->data=7;     first->next=second;
    second->prev=first;   second->data=8;    second->next=third;
    third->prev=second;   third->data=3;     third->next=NULL;
    display(head);

    //insert at front
    head=insert_at_front(head,55);
    display(head);
    //insert at end
    head=insert_at_end(head,65);
    display(head);
    //insert at index
    head=insert_at_index(head,2,36);
    display(head);

    //delete at front
    head=delete_at_front(head);
    display(head);
    //delete at end
    head=delete_at_end(head);
    display(head);
    return 0;
}




                                       //doubly circular linked list
//Doubly linked list

// #include<stdio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node *prev;
//     struct node *next;
// };
// struct node *head=NULL;


// void display(struct node *head){
//     struct node *ptr=head;
//     while(ptr->next!=head){
//         printf("%d\t",ptr->data);
//         ptr=ptr->next;
//     }
//     printf("%d\n",ptr->data);
// }

//                                 //doubly circular linked list insertion
// //insert at front
// struct node *insert_at_front(struct node *head,int val){
//     struct node *ptr=(struct node *)malloc(sizeof(struct node));
//     struct node *p=head;
//     while(p->next!=head){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->prev=p;
//     ptr->data=val;
//     ptr->next=head;
//     return ptr;

// }
// //insert at end
// struct node *insert_at_end(struct node *head,int val){
//     struct node *ptr=(struct node *)malloc(sizeof(struct node));
//     struct node *p=head;
//     while(p->next!=head){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->prev=p; ptr->data=val; ptr->next=head;
//     return head;
// }

// //insert at index (only works for   1<index<size-1)
// struct node *insert_at_index(struct node *head,int index,int val){
//     struct node *ptr=(struct node *)malloc(sizeof(struct node));
//     struct node *p;
//     struct node *q;
//     if(index==0){
//         p=q=head;
//         while(p->next!=head){
//             p=p->next;
//         }
//         p->next=ptr;
//         ptr->next=head;
//         ptr->data=val;
//         ptr->prev=p;
//         return ptr;
//     }
//     p= head->next;
//     q=head;
//     int i=0;
//     while(i!=index-1){
//         p=p->next;
//         q=q->next;
//         i++;
//     }
//     ptr->next=p;
//     p->prev=ptr;
//     q->next=ptr;
//     ptr->prev=q;
//     ptr->data=val;
//     return head;
// }
//                                       //Deletion in doubly circular linked list
// //delete at front
// struct node *delete_at_front(struct node *head){
//     struct node *p=head->next;
//     struct node *q=head->next;
//     while(p->next!=head){
//         p=p->next;
//     }
//     p->next=q;
//     q->prev=p;
//     free(head);
//     return q;
// }
// //delete at end
// struct node *delete_at_end(struct node *head){
//     struct node *p=head->next;
//     struct node *q=head;
//     while(p->next!=head){
//         p=p->next;
//         q=q->next;
//     }
//     q->next=head;
//     head->prev=q;
//     free(p);
//     return head;

// }
// int main(){
//     //creating the linked list with 4 nodes
//     struct node *head=(struct node *)malloc(sizeof(struct node));
//     struct node *first=(struct node *)malloc(sizeof(struct node));
//     struct node *second=(struct node *)malloc(sizeof(struct node));
//     struct node *third=(struct node *)malloc(sizeof(struct node));
//     head->prev=third;      head->data=5;      head->next=first;
//     first->prev=head;     first->data=7;     first->next=second;
//     second->prev=first;   second->data=8;    second->next=third;
//     third->prev=second;   third->data=3;     third->next=head;
//     display(head);

//     //insert at front
//     head=insert_at_front(head,55);
//     display(head);
//     //insert at end
//     head=insert_at_end(head,65);
//     display(head);
//     //insert at index
//     head=insert_at_index(head,0,36);
//     display(head);
//     //insert at index
//     head=insert_at_index(head,6,36);
//     display(head);

//     //delete at front
//     head=delete_at_front(head);
//     display(head);
//     //delete at end
//     head=delete_at_end(head);
//     display(head);
//     return 0;
// }