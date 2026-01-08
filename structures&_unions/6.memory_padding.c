#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

struct s_node{        //singly linked list
    int data;
    struct s_node *next;
};

struct d_node {
    int data;
    struct d_node *prev;
    struct d_node *next;
};

int main(){
    printf("%lu\n",sizeof(struct stack));
    printf("%lu\n",sizeof(struct queue));
    printf("%lu\n",sizeof(struct s_node));
    printf("%lu\n",sizeof(struct d_node));
    /* The output should be 16, 20, 12, 20 bytes  but due to memory padding 
    
    struct stack: 16 bytes 
        int size: 4 bytes
        int top: 4 bytes
        int *arr: 8 bytes
        Total: 16 bytes (already aligned)

    struct queue: 24 bytes (not 20)
        int size: 4 bytes
        int f: 4 bytes
        int r: 4 bytes
        4 bytes padding (to align the pointer to 8-byte boundary)
        int *arr: 8 bytes
        Total: 24 bytes

    struct s_node: 16 bytes (not 12)
        int data: 4 bytes
        struct s_node *next: 8 bytes
        4 bytes padding (to make total 16, aligned to 8-byte boundary)
        Total: 16 bytes

    struct d_node: 24 bytes (not 20)
        int data: 4 bytes
        4 bytes padding (to align first pointer)
        struct d_node *prev: 8 bytes
        struct d_node *next: 8 bytes
        Total: 24 bytes

    The padding is added automatically by the compiler to ensure
    efficient memory alignment, even though it wastes a few bytes.

    */
    return 0;
}
