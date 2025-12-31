//stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;       //global top node declared. [null pointer]

int is_empty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int is_full(){
    struct node *n=(struct node*)malloc(sizeof(struct node));   //if allocation fails the stack full
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int val){
    struct node *n=(struct node*)malloc(sizeof(struct node)); 
    if(n==NULL){
        printf("stack overflow\n");        //if allocation fails the stack full
    }
    n->next=top;
    n->data=val;
    top=n;
}
void pop(){
    if(is_empty()){
        printf("stack underflow\n");
    }
    else{
        struct node *p=top;
        top=top->next;
        int x=p->data;
        free(p);
        printf("%d popped\n",x);
    }
}
void display(){
    struct node *p=top;
    while(p->next!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}
void stacktop(){
    if(!is_empty()){
        printf("stack top=%d\n",top->data);
    }
}
void stackbottom(){
    if(!is_empty()){
        struct node *p=top;
        while(p->next!=NULL){
            p=p->next;
        }
        printf("stack bottom:%d\n",p->data);
    }
}

int main(){
    printf("is empty:%d\n",is_empty());
    push(9);
    display();

    push(10);
    display();

    push(11);
    display();

    push(12);
    display();

    pop();
    display();

    pop();
    display();
    stacktop();

    display();
    stackbottom();
    pop();
    pop();
    pop();


    return 0;
}