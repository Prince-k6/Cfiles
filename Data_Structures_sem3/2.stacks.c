//implementing stacks using array structures

#include<stdio.h>
#include<stdlib.h>    //for using dynamic memory allocation

//creating a array named stack using structures
struct stack{
    int size;
    int top;                     //made an array using structures, now using this array we'll create a stack
    int *arr;
};

 //passing a pointer stack into is_empty function
void is_empty(struct stack *ptr){                 //when stack is empty stack pointer is equal to -1
    if (ptr->top==-1){
        // return 1;  
        printf("stack is empty\n");
    }else{
        // return 0;
        printf("stack is not empty\n");
    }
}

void is_full(struct stack *ptr){             //when stack is full the stack pointer is equal to size-1
    if(ptr->top==ptr->size-1){
        // return 1;
        printf("stack is full\n");
    }else{
        // return 0;
        printf("stack is not full\n");
    }
}
 
void push(struct stack *ptr,int a){           //ptr=stack
    if(ptr->top==ptr->size-1){
        printf("overflow occured!,cannot push more\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=a;
        printf("%d pushed to stack\n\n",a);
    }
}
void pop(struct stack *ptr){
    if(ptr->top==-1){
        printf("underflow occured!,cannot pop more\n");
    }else{
        printf("%d popped\n",ptr->arr[ptr->top]);
        ptr->top--;
    }
}

void display(struct stack *ptr){
    if(ptr->top==-1){
        printf("stack is empty\n");
    }else{
        printf("stack elements are\n");
        for(int i=0;i<=ptr->top;i++){
            printf("%d\t",ptr->arr[i]);
        }
        printf("\n");
    }
}

void peek(struct stack *ptr,int index){     //peek function returns/prints the value at a particular index
    if ((index>ptr->top)&&(index<ptr->size)){
        printf("empty position\n");
    }else if(index>=ptr->size){
        printf("index out of bound\n");
    }else{
        printf("value at index %d is %d\n",index,ptr->arr[index]);
    }
}



int main(){
    // struct stack s;          //stack declaration
    // s.size=80;               //lets say the size is 80 (fixed size)
    // s.top=-1;                //-1 indicates empty 
    // s.arr=(int*)malloc(s.size*sizeof(int));  //allocating the memory for stack s using dynamic memory allocation

    struct stack *s;     //using pointer variable       
    s->size=5;               
    s->top=-1;               
    s->arr=(int*)malloc(s->size*sizeof(int));  

    // is_empty(s);
    // is_full(s);
    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    display(s);
    pop(s);
    pop(s);
    display(s);
    peek(s,0);      //gives value at index 0
    peek(s,1);       //gives value at index 1
    peek(s,4);       //will show empty position
    peek(s,10);      //will show out of bound

    return 0;
}
