#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top=-1;
char infix[MAX],postfix[MAX];

void push(char c){
    if(top==MAX-1){
        return;
    }
    top++;
    stack[top]=c;
}
char pop(){
    if(top==-1){
        return -1;
    }
    return stack[top--];
    // char x=stack[top];
    // top--;
    // return x;  //or directly return stack[top--];
}
int isempty(){
    return top==-1;
}
/*====================Precedence function=========================*/
int prec(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    if(ch=='*' || ch=='/' || ch=='%'){
        return 2;
    }
    if(ch=='^'){
        return 3;
    }
    return 0;
}
void evaluate(){
    int i=0;
    int j=0;
    char ch;
    while(infix[i]!='\0'){
        ch=infix[i];
        if(isalnum(ch)){
            postfix[j]=ch;
            j++;
        }else{
            if(ch=='('){
                push(ch);
            }else if(ch==')'){
                char x=pop();
                while(x!='('){
                    postfix[j]=x;
                    j++;
                    x=pop();
                }
            }else{
                while(!isempty() && prec(stack[top]) >= prec(ch)){
                    postfix[j]=pop();
                    j++;
                }
                push(ch);
            }
        }
        i++;
    }
    //pop all remaining operators
    while(!isempty()){
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
}

int main(){
    printf("Enter Infix Expression:");
    scanf("%s",infix);
    evaluate();
    printf("postfix Expression: %s\n",postfix);
    return 0;

}
