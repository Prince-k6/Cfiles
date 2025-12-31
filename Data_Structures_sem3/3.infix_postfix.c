#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{                //stack banya
    int size;
    int top;
    char *arr;
};
//stack operations
void push(struct stack *s,char ch){
    if (s->top==s->size-1){
        printf("stack overflow\n");
    }else{
        s->top++;
        s->arr[s->top]=ch;
    }
}
char pop(struct stack *s){
    if (s->top==-1){
        printf("stack underflow\n");
        return -1;
    }else{
       char ch=s->arr[s->top];
       s->top--;
       return ch;
    }
}
int isempty(struct stack *s){
    if (s->top==-1){
        return 1;
    }else{
        return 0;
    }
}
char stacktop(struct stack *s){
    return s->arr[s->top];
}

//precedence function
int prec(char ch){
    if (ch=='*'|| ch=='/'){
        return  3;
    }
    else if(ch=='+'||ch=='-'){
        return 2;
    }
    else{
        return 0; 
    }
}
//is operator function to check whether a character is operator or not
int isoperator(char ch){
    if(ch=='+' || ch=='-' || ch =='*'|| ch=='/'){
        return 1;
    }else{
        return 0;
    }
}
//infix to postfix convertor function
char *infix_to_postfix(char *infix){
    //declared a pointer variable of data type stack, sp=stack pointer
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));    //stores operators
    sp->size=30;   //can be anything else
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));

    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));   //final expression will stored in this

    int i=0;   //for infix scan
    int j=0;   //for postfix push
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else{
            if(prec(infix[i])>prec(stacktop(sp))){    //prec=precendence function
                push(sp,infix[i]);
                i++;
            }     
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while (!isempty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char * infix;
    printf("enter infix expression:");
    scanf("%s",infix);        //fegts(infix,30,stdin) --> instead of '\o' -> '\n' will come
    printf("postfix of expression: %s = %s \n",infix,infix_to_postfix(infix));

    return 0;
}