/*
2. Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix Expression. 
Program should support for both parenthesized and free parenthesized expressions with the 
operators: +, -, *, /, %( Remainder), ^ (Power) and alphanumeric operands.

eg:a+b*c = abc*+

*/

#include<stdio.h>
#include<stdlib.h>

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
int isoperator(char op){
    if(op=='(' || op==')' || op=='+' || op=='-' || op=='*' || op=='/' || op=='%' || op=='^'){
        return 1;
    }else{
        return 0;
    }
}
void evaluate(){
    int i=0;    //for infix scan
    int j=0;    //for assigning to postfix
    char symb;
    while(infix[i]!='\0'){
        symb=infix[i];
        if(!isoperator(symb)){
            postfix[j]=symb;
            j++;
        }else if(symb=='('){
            push(symb);
        }else if(symb==')'){
            char x=pop();
            while(x!='('){
                postfix[j]=x;
                j++;
                x=pop();
            }
        }else{
            while(!isempty() && prec(stacktop()) >= prec(symb)){
                postfix[j]=pop();     //pop and assign to postfix[j]  if prec of stacktop is >= infix[i]
                j++;
            }
            push(symb);
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
