//Write a C program to merge two sorted lists into a single sorted list

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
    if(head==NULL){
        return new;
    }
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
struct node* mergeTwoLists(struct node* head1, struct node* head2){
    struct node *result=NULL;
    struct node *temp1=head1;
    struct node *temp2=head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            result=insert_atend(result,temp1->data);
            temp1=temp1->next;
        }else{
            result=insert_atend(result,temp2->data);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        result=insert_atend(result,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        result=insert_atend(result,temp2->data);
        temp2=temp2->next;
    }
    return result;

}

int main(){
    struct node *head1=createNode(1);
    head1=insert_atend(head1,2);
    head1=insert_atend(head1,4);
    display(head1);

    struct node *head2=createNode(1);
    head2=insert_atend(head2,3);
    head2=insert_atend(head2,4);
    display(head2);

    struct node *merge=mergeTwoLists(head1,head2);
    display(merge);



    return 0;
}