#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char infix[30];    //original expression
char postfix[30];   //final exprssion
char stack[30];     //medium of conversion (push , pop will be performed on this)
int top=-1;

void push(char item){
    if(top==30-1){
        printf("overflow\n");
    }else{
        top++;
        stack[top]=item;
    }
}
char pop(){
    if(top==-1){
        printf("underflow\n");
        return -1;
    }
    char x = stack[top];
    top--;
    return x;
}
char stacktop(){
    return stack[top];
}
int isempty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}
int prec(char op){
    int p;
    if(op=='(' || op ==')'){
        p=0;}
    if(op=='+' || op=='-'){
        p=1;}
    if(op=='*' || op=='/' || op=='%'){
        p=2;}
    if(op=='^'){
        p=3;}
    return p;
}
void evaluate(){
    int i=0;    //for infix scan
    int j=0;    //for assigning to postfix
    char ch;
    while(infix[i]!='\0'){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[j]=ch;
            j++;
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            char x=pop();
            while(x!='('){
                postfix[j]=x;
                j++;
                x=pop();
            }
        }else{
            while(!isempty() && prec(stacktop()) >= prec(ch)){
                postfix[j]=pop();     //pop and assign to postfix[j]  if prec of stacktop is >= infix[i]
                j++;
            }
            push(ch);
        }
        i++;
    }
    while(!isempty()){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';

}
int main(){
    printf("enter the infix expression: ");
    scanf("%s",infix);
    evaluate();
    printf("postfix expression is: %s\n",postfix);
    return 0;
}