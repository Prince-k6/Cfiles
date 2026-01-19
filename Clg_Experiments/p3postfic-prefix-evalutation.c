/*
3. Design, Develop and Implement a Program in C for the following Stack Applications Evaluation of 
Suffix/postfix  expression with single digit operands and operators: +, -, *, /, %, ^ 
*/

#include<stdio.h>
#include<stdlib.h>     //for exit()
#include<ctype.h>      //for isdigit() function
#include<math.h>       //for pow() function
#include<string.h>     //for strlen()

#define MAX 100
int stack[MAX];           //stack made
int top=-1;


void push(char ch){
    if(top==MAX-1){
        printf("stack overflow\n");
    }else{
        top++;
        stack[top]=ch;
    }
}
int pop(){
    if(top==-1){
        printf("stack underflow\n");
        exit(0);
    }else{
        int x=stack[top];
        top--;
        return x;
    }
}
int eval_prefix_exp(char *expression){
    int op1,op2,result;
    for(int i=strlen(expression)-1;i>=00;i--){
        if(isdigit(expression[i])){
            push(expression[i]-'0');     // expression-'0' or else ascii value will be stored [char1-char2=int value]
            //int value will be pushed to stack not char.   ....basically it is for converting into integer value
        }else{    //if it is not digti then it must be operator
            op1=pop();           //operand2 first because its a postfix expression 
            op2=pop();           //on scanning from left->right operand1 will be popped later and op1 will be popped first
            switch(expression[i]){
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                case '%':
                    result=op1%op2;
                    break;
                case '^':
                    result=pow(op1,op2);
                    break;
                default:
                    printf("invalid opertor...\n");
                    exit(0);
            }
            push(result);
        }
    }
    return pop();
}

int eval_postfix_exp(char *expression){
    int op1,op2,result;
    for(int i=0;i<strlen(expression);i++){
        if(isdigit(expression[i])){
            push(expression[i]-'0');     // expression-'0' or else ascii value will be stored [char1-char2=int value]
            //int value will be pushed to stack not char.   ....basically it is for converting into integer value
        }else{    //if it is not digti then it must be operator
            op2=pop();           //operand2 first because its a postfix expression 
            op1=pop();           //on scanning from left->right operand1 will be popped later and op1 will be popped first
            switch(expression[i]){
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                case '%':
                    result=op1%op2;
                    break;
                case '^':
                    result=pow(op1,op2);
                    break;
                default:
                    printf("invalid opertor...\n");
                    exit(0);
            }
            push(result);
        }
    }
    return pop();
}


int main(){
    // char expression1[MAX];
    // printf("enter postfix expression:");
    // scanf("%s",expression1);
    // int result1=eval_postfix_exp(expression1);
    // printf("Result of postfix expression: %d\n",result1);

    char expression2[MAX];
    printf("enter prefix expression:");
    scanf("%s",expression2);
    int result2=eval_prefix_exp(expression2);
    printf("Result of prefix expression: %d\n",result2);
    return 0;
}
