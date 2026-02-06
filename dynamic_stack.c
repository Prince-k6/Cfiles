#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int main(){
    // struct stack *s;
    // s->size=6;
    // s->top=-1;
    // s->arr=(int *)malloc(s->size*sizeof(int));   //allocating memory ot stack


    // s->arr[2]=3;
    // s->arr[3]=3;
    // printf("%d\n",s->arr[2]);
    // printf("%d\n",s->top);
    // return 0;

    struct stack s;
    s.size=6;
    s.top=-1;
    s.arr=(int *)malloc(s.size*sizeof(int));   //allocating memory ot stack


    s.arr[2]=3;
    s.arr[3]=3;
    printf("%d\n",s.arr[2]);
    printf("%d\n",s.top);
    return 0;
}