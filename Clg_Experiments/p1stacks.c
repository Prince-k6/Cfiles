/*
Design, Develop and Implement a menu driven Program in C for the following
operations on STACK of Integers (Array Implementation of Stack with maximum size MAX)
    a. Push an Element on to Stack
    b. Pop an Element from Stack
    c. Demonstrate Overflow and Underflow situations on Stack
    d. Display the status of Stack
    e. Exit
Support the program with appropriate functions for each of the above operations.

*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int stack[MAX];
int top=-1;

void push(int val){
    if(top==MAX-1){
        printf("cannnot push,overflow\n");
    }else{
        top++;
        stack[top]=val;
    }
}
void pop(){
    if(top==-1){
        printf("cannot pop, underflow\n");
    }else{
        int x=stack[top];
        printf("%d removed\n",x);
        // return x;
        top--;
    }
}
void display(){
    if(top==-1){
        printf("stack is empty\n");
    }else{
        for(int i=top;i>=0;i--){
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice,element;
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display\n");
    printf("4.exit\n");
    while(choice!=4){
        printf("enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter element to push:");
                scanf("%d",&element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("elements in stack\n");
                display();
                break;
            case 4:
                printf("exiting program...\n");
                exit(0);
            default:
                printf("invalid choice try again\n");
        }
    }
    return 0;
}