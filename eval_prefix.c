#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int val){
    if(top==MAX-1){
        return ;
    }
    stack[++top]=val;
}
int pop(){
    if(top==-1){
        return -1;
    }
    return stack[top--];
}

int eval_prefix(char *exp){
    int op1,op2,result;
    for(int i=strlen(exp)-1;i>=0;i--){
        if(isdigit(exp[i])){
            push(exp[i]-'0');
        }else{
            op1=pop();
            op2=pop();
            switch(exp[i]){
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
                    printf("invalid operator\n");
                    break;
            }
            push(result);
        }
    }
    return pop();
}


int main(){
    char exp[MAX];
    printf("Enter prefix expression:");
    scanf("%s",exp);
    printf("answer=%d\n",eval_prefix(exp));
    return 0;
}

