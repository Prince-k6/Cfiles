//WAP to rverse a string usinf array and user defined functions that uses LIFO principle
//demonstrate the operations and display the reversed string
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top=-1;


void push(char ch){
    if(top==MAX-1){
        return;
    }
    stack[++top]=ch;
}
char pop(){
    if(top==-1){
        return -1;
    }
    return stack[top--];
}
void reverse(char str[]){
    char rev[MAX];
    int i;
    for(i=0;str[i]!='\0';i++){
        push(str[i]);
    }
    for(i=0;str[i]!='\0';i++){
        rev[i]=pop();
    }
    rev[i]='\0';
    printf("Rversed string : %s\n",rev);


}

int main(){
    char str[MAX];
    printf("Enter string:");
    scanf("%s",str);
    reverse(str);


    return 0;
}

